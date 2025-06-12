#include <stdio.h>
#define N 5

void Int_Sum(void *sum, void *num);
void Int_Sub(void *sum, void *num);
void Init(void *p);
int Int_Comp(void *a, void *b);
int Do_It(void *sum, void **array, void (*p_Init)(void *), void (*p_Sum)(void *, void *), void (*p_Sub)(void *, void *), int (*p_Comp)(void *, void *));

int main()
{
  int num[] = {5, 8, 23, 20, 23}, i, answer;
  void *p_num[N];

  // Get andress of numbers
  for (i = 0; i < N; i++)
  {
    p_num[i] = &num[i];
  }

  answer = Do_It(&answer, p_num, Init, Int_Sum, Int_Sub, Int_Comp);
  if (answer == 1)
    printf("The answer is 'Yes'");
  else
    printf("The answer is 'No'");

  return 0;
}

// Sum 2 numbers
void Int_Sum(void *sum, void *num)
{
  *(int *)sum += *(int *)num;
}

// Substract 2 numbers
void Int_Sub(void *sum, void *num)
{
  *(int *)sum -= *(int *)num;
}

// Initialize number
void Init(void *p)
{
  *(int *)p = 0;
}

// Comapare 2 numbers
int Int_Comp(void *a, void *b)
{
  if (*(int *)a == *(int *)b)
    return 1;
  return 0;
}

// Sum all even and sub all odd numbers and compare sum to number in array
int Do_It(void *sum, void **array, void (*p_Init)(void *), void (*p_Sum)(void *, void *), void (*p_Sub)(void *, void *), int (*p_Comp)(void *, void *))
{
  int i;
  p_Init(sum);

  for (i = 0; i < N; i++)
  {
    // Comapre sum to number in array
    if (p_Comp(sum, array[i]))
      return 1;

    // Odd number
    if (i % 2)
      p_Sub(sum, array[i]);
    // Even number
    else
      p_Sum(sum, array[i]);
  }
  return 0;
}
