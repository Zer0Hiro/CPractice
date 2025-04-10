#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// This funciton will find middle point between 2 points 
void Set_Mid(double, double, double, double, double*, double*);

int main()
{
	double x1, y1, x2, y2, midx, midy, check;
	int i;
	for (i = 0; i < 2;)
	{	
		printf("Input Point coordinates (x,y): ");
		switch (i)
		{
		case(0):
			check = scanf("%lf %lf", &x1, &y1);
			break;
		case(1):
			rewind(stdin);
			check = scanf("%lf %lf", &x2, &y2);
			break;
		default:
			printf("Wrong input!\n");
			break;
		}
		if (check == 2) i++;
		else printf("Wrong input!\n");
	}
	Set_Mid(x1, y1, x2, y2, &midx, &midy);
	printf("The middle point will be: (%g ,%g)\n", midx, midy);
	return 1;
}

// Count
void Set_Mid(double x1, double y1, double x2, double y2, double* p_mx, double* p_my)
{
  
	*p_mx = (x1 + x2) / 2;
	*p_my = (y1 + y2) / 2;
}