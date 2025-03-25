#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	float x;
	double res;
	printf("Enter x please: ");
	scanf("%f", &x);
	res = x + pow(1.0/3*pow(x,4)+2*pow(x,0.5), 0.2);

	printf("x+(1/3x^4+2x^(1/2))^(1/5) = ");
	printf("%.2lf+(1/3*%.2lf^4+2*%.2lf^(1/2))^(1/5) = %.2lf \n", x, x, x, (float)res);
	
	printf("x+(1/3x^4+2x^(1/2))^(1/5) = ");
	printf("%g+(1/3*%g^4+2*%g^(1/2))^(1/5) = %g ", x, x, x, (float)res);
	return 0;
}