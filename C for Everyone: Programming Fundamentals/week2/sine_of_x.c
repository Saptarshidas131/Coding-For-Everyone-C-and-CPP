#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, result;
	printf("Enter a number: ");
	scanf("%lf",&x);
	result = sin(x);
	printf("%lf",result);
	return 0;
}
