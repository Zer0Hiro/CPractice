/*
  Title: Flowfield Aurora — High-Quality Canvas Animation

  Plan / Design Notes:
  - Create a visually rich, long-running animation that stays interesting well beyond {{VIDEO_DURATION_SECONDS}} seconds.
  - Use a curl-noise flow field to move thousands of particles in smooth, organic paths.
  - Render with additive blending ("lighter") and subtle motion blur to create an aurora / nebula vibe.
  - Multi-layer rendering: base particles + ribbon trails + occasional sparkle / star pulses.
  - Colors: cycle hues across a cool-to-warm spectrum; vary by particle age & speed.
  - Interactivity: pointer acts as a gentle attractor/repulsor to let users sculpt the flow without breaking it.
  - High quality touches: vignette, filmic bloom via downsampled offscreen buffer, dynamic resolution awareness, and time-based updates.
  - No frameworks. Only the HTML Canvas API. The page already has <canvas id="canvas">.

  Performance/Quality Strategy:
  - Use requestAnimationFrame and time-delta to keep motion consistent at different refresh rates.
  - Use offscreen canvas for bloom; keep resolution adaptive to main canvas bounds (read-only, never set main width/height).
  - Use batched drawing and few state changes.

  Constraints satisfied:
  - We DO NOT set canvas.width or canvas.height (we only read them).
  - We access the canvas with the exact required lines.
  - Animation starts automatically on script run.
*/

// --- Canvas Setup (read-only with respect to size) ---
const canvas = document.getElementById('canvas');
const ctx = canvas.getContext('2d');

// We'll read these often to adapt to current canvas size without writing to it.
function cw() { return canvas.width; }
function ch() { return canvas.height; }

// Offscreen canvas for bloom/blur (we are allowed to set THIS one's size)
const bloom = document.createElement('canvas');
const bctx = bloom.getContext('2d');

function resizeOffscreen() {
  // Match offscreen size to current main canvas size (read only from main)
  bloom.width = Math.max(1, cw() >> 1);  // downsample 2x for soft blur
  bloom.height = Math.max(1, ch() >> 1);
}
resizeOffscreen();

// --- Utilities ---
const TAU = Math.PI * 2;
const rand = (a=1, b=0) => b + (a - b) * Math.random();
const clamp = (v, lo, hi) => Math.max(lo, Math.min(hi, v));
const lerp = (a, b, t) => a + (b - a) * t;

// Map value in [inMin,inMax] to [outMin,outMax]
function map(v, inMin, inMax, outMin, outMax) {
  const t = (v - inMin) / (inMax - inMin);
  return outMin + (outMax - outMin) * t;
}

// --- Simplex Noise (2D) ---
// Lightweight 2D simplex noise adapted for visual flow. Time used as z via domain warp.
class Simplex2D {
  constructor(seed=123456) {
    this.p = new Uint8Array(256);
    let s = seed >>> 0;
    for (let i = 0; i < 256; i++) {
      s = (s * 1664525 + 1013904223) >>> 0;
      this.p[i] = s & 255;
    }
    this.perm = new Uint8Array(512);
    for (let i = 0; i < 512; i++) this.perm[i] = this.p[i & 255];
    this.g = new Float32Array(512 * 2);
    for (let i = 0; i < 512; i++) {
      const a = (this.perm[i] / 255) * TAU;
      this.g[i*2] = Math.cos(a);
      this.g[i*2+1] = Math.sin(a);
    }
  }
  dot(ix, iy, x, y) {
    const idx = this.perm[ix + this.perm[iy]] * 2;
    return this.g[idx] * x + this.g[idx+1] * y;
  }
  noise(xin, yin) {
    const F2 = 0.5 * (Math.sqrt(3) - 1);
    const G2 = (3 - Math.sqrt(3)) / 6;
    let s = (xin + yin) * F2;
    let i = Math.floor(xin + s);
    let j = Math.floor(yin + s);
    const t = (i + j) * G2;
    const X0 = i - t, Y0 = j - t;
    const x0 = xin - X0, y0 = yin - Y0;

    let i1, j1;
    if (x0 > y0) { i1 = 1; j1 = 0; } else { i1 = 0; j1 = 1; }

    const x1 = x0 - i1 + G2;
    const y1 = y0 - j1 + G2;
    const x2 = x0 - 1 + 2 * G2;
    const y2 = y0 - 1 + 2 * G2;

    i &= 255; j &= 255;

    let n0 = 0, n1 = 0, n2 = 0;

    let t0 = 0.5 - x0*x0 - y0*y0;
    if (t0 > 0) { t0 *= t0; n0 = t0 * t0 * this.dot(i, j, x0, y0); }

    let t1 = 0.5 - x1*x1 - y1*y1;
    if (t1 > 0) { t1 *= t1; n1 = t1 * t1 * this.dot(i + i1, j + j1, x1, y1); }

    let t2 = 0.5 - x2*x2 - y2*y2;
    if (t2 > 0) { t2 *= t2; n2 = t2 * t2 * this.dot(i + 1, j + 1, x2, y2); }

    return 70 * (n0 + n1 + n2); // [-1, 1] approximately
  }
}

// --- Flow Field via Curl of Noise ---
const noise = new Simplex2D((Math.random()*1e9)|0);
function curl(x, y, t) {
  const e = 0.001; // small epsilon for numerical derivative
  // domain warp
  const wx = x * 0.0017 + 0.3 * Math.sin(t * 0.12);
  const wy = y * 0.0017 + 0.3 * Math.cos(t * 0.09);

  const n1 = noise.noise(wx + e, wy + t*0.05);
  const n2 = noise.noise(wx - e, wy + t*0.05);
  const n3 = noise.noise(wx, wy + e + t*0.05);
  const n4 = noise.noise(wx, wy - e + t*0.05);

  const dx = (n1 - n2) / (2*e);
  const dy = (n3 - n4) / (2*e);
  // rotate gradient 90 degrees to get curl-like field
  return { x: dy, y: -dx };
}

// --- Particle System ---
const MAX_PARTICLES = 2200;
const particles = new Array(MAX_PARTICLES);

class Particle {
  constructor(i) { this.reset(i); }
  reset(i) {
    // distribute starting points along a concentric ring
    const r = Math.sqrt(Math.random()) * Math.min(cw(), ch()) * 0.45;
    const a = rand(TAU);
    this.x = cw()/2 + Math.cos(a)*r;
    this.y = ch()/2 + Math.sin(a)*r;
    this.vx = 0; this.vy = 0;
    this.life = 0;
    this.maxLife = 800 + (Math.random()*1200)|0;
    this.size = rand(0.6, 1.6);
    this.hueOffset = rand(0, 360);
    this.twinkle = Math.random() < 0.02 ? 1 : 0; // rare sparkle
  }
  step(dt, t) {
    const k = curl(this.x, this.y, t);
    // base flow
    const force = 60;
    this.vx = lerp(this.vx, k.x * force, 0.05);
    this.vy = lerp(this.vy, k.y * force, 0.05);

    // mild attraction/repulsion to pointer
    const dx = pointer.x - this.x;
    const dy = pointer.y - this.y;
    const d2 = dx*dx + dy*dy;
    if (d2 < pointer.radius*pointer.radius) {
      const d = Math.sqrt(d2) + 0.0001;
      const u = dx / d, v = dy / d;
      const amp = (pointer.mode === 1 ? 45 : -30) * (1 - d/pointer.radius);
      this.vx += u * amp;
      this.vy += v * amp;
    }

    this.x += this.vx * dt;
    this.y += this.vy * dt;

    // wrap around edges softly
    const W = cw(), H = ch();
    const m = 4; // margin
    if (this.x < -m) this.x = W + m;
    if (this.x > W + m) this.x = -m;
    if (this.y < -m) this.y = H + m;
    if (this.y > H + m) this.y = -m;

    this.life++;
    if (this.life > this.maxLife) this.reset();
  }
  draw(ctx, t) {
    const speed = Math.hypot(this.vx, this.vy);
    const hue = (this.hueOffset + map(Math.sin(t*0.05 + this.hueOffset), -1, 1, 0, 180) + speed*0.4) % 360;
    const alpha = clamp(map(speed, 0, 80, 0.1, 0.7), 0.06, 0.8) * (this.twinkle ? 1.5 : 1);

    ctx.globalCompositeOperation = 'lighter';
    ctx.lineWidth = this.size;
    ctx.strokeStyle = `hsla(${hue}, 90%, ${map(speed,0,80,60,72)}%, ${alpha})`;

    ctx.beginPath();
    ctx.moveTo(this.x, this.y);
    ctx.lineTo(this.x - this.vx*0.02, this.y - this.vy*0.02);
    ctx.stroke();

    if (this.twinkle && Math.random() < 0.02) {
      // occasional star pulse
      const r = clamp(speed*0.03, 0.5, 2.5);
      ctx.fillStyle = `hsla(${hue}, 100%, 80%, ${alpha*1.2})`;
      ctx.beginPath();
      ctx.arc(this.x, this.y, r, 0, TAU);
      ctx.fill();
    }
  }
}

for (let i = 0; i < MAX_PARTICLES; i++) particles[i] = new Particle(i);

// --- Pointer Interactivity ---
const pointer = { x: cw()/2, y: ch()/2, radius: Math.min(cw(), ch())*0.25, mode: 1 };
window.addEventListener('pointermove', e => {
  const rect = canvas.getBoundingClientRect();
  pointer.x = (e.clientX - rect.left) * (cw() / rect.width);
  pointer.y = (e.clientY - rect.top) * (ch() / rect.height);
});
window.addEventListener('click', () => { pointer.mode *= -1; }); // toggle attract/repel

// --- Background & Vignette ---
function drawBackground(dt) {
  // subtle motion blur for trails
  ctx.save();
  ctx.globalCompositeOperation = 'source-over';
  ctx.globalAlpha = 0.12; // lower alpha = longer trails
  const grad = ctx.createLinearGradient(0, 0, 0, ch());
  grad.addColorStop(0, '#060611');
  grad.addColorStop(1, '#0a0f1f');
  ctx.fillStyle = grad;
  ctx.fillRect(0, 0, cw(), ch());
  ctx.restore();

  // vignette
  const g = ctx.createRadialGradient(cw()*0.5, ch()*0.55, Math.min(cw(), ch())*0.15, cw()*0.5, ch()*0.5, Math.max(cw(), ch())*0.65);
  g.addColorStop(0, 'rgba(0,0,0,0)');
  g.addColorStop(1, 'rgba(0,0,0,0.35)');
  ctx.fillStyle = g;
  ctx.fillRect(0, 0, cw(), ch());
}

// --- Bloom (downsample + blur-ish scale) ---
function drawBloomLayer() {
  // copy main canvas to offscreen downsampled, then scale back up additively
  if (bloom.width === 0 || bloom.height === 0) return;
  bctx.clearRect(0, 0, bloom.width, bloom.height);
  // draw a subset: mainly bright content via lighter blend
  bctx.globalCompositeOperation = 'source-over';
  bctx.drawImage(canvas, 0, 0, bloom.width, bloom.height);

  // back to main with lighter blend & slightly larger to fake blur
  ctx.save();
  ctx.globalCompositeOperation = 'lighter';
  ctx.globalAlpha = 0.55;
  ctx.drawImage(bloom, -2, -2, cw()+4, ch()+4);
  ctx.restore();
}

// --- Animation Loop ---
let last = performance.now();
function frame(now) {
  const dt = clamp((now - last) / 1000, 0.001, 0.033); // seconds
  last = now;

  drawBackground(dt);

  const t = now * 0.001;
  // draw particles
  for (let i = 0; i < particles.length; i++) {
    const p = particles[i];
    p.step(dt, t);
    p.draw(ctx, t);
  }

  drawBloomLayer();

  requestAnimationFrame(frame);
}

// Handle resize: only offscreen needs resizing; we never touch main canvas size
function onResize() { resizeOffscreen(); pointer.radius = Math.min(cw(), ch())*0.25; }
window.addEventListener('resize', onResize);

// Kick off with a solid background clear
(function init() {
  ctx.fillStyle = '#070a14';
  ctx.fillRect(0, 0, cw(), ch());
  requestAnimationFrame(frame);
})();

// Optional: subtle title watermark (fades in/out without distracting)
(function watermark() {
  let alpha = 0;
  let dir = 1;
  function tick() {
    alpha += dir * 0.003;
    if (alpha > 0.08) { alpha = 0.08; dir = -1; }
    if (alpha < 0.0) { alpha = 0.0; dir = 1; }
    ctx.save();
    ctx.globalCompositeOperation = 'lighter';
    ctx.globalAlpha = alpha;
    ctx.font = `${Math.max(14, Math.min(cw(), ch())*0.02)}px sans-serif`;
    ctx.textAlign = 'right';
    ctx.fillStyle = 'rgba(200,220,255,0.9)';
    ctx.fillText('Flowfield Aurora', cw()-12, ch()-12);
    ctx.restore();
    requestAnimationFrame(tick);
  }
  tick();
})();

// FRAMEWORK_COMMAND: SUBMIT_FINAL_CODE
