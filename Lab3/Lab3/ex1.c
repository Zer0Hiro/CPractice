#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
	double weight, height, bmi;
	printf("Please enter weight (in kg) and height (in cm), respectively:");
	scanf("%lf %lf", &weight, &height);

	//Calculates the BMI 
	bmi = weight / pow(height / 100.0, 2);
	//Check to which group this person connected
	if (bmi < 18.5) printf("Underweight");
	else if (bmi >= 18.5 && bmi < 25) printf("Normal weight");
	else if (bmi >= 25 && bmi < 30) printf("Increased weight");
	else if (bmi >= 30 && bmi < 40) printf("Obese");
	else if (bmi >= 40) printf("Very high obese");
	else return 0;
}
