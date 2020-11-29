#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
int main(void)
{ 
double interval, sine=0, abso=0;
int i;
for(i = 0; i <30; i++)
{
 interval = i/10.0;
 // calculating sine of interval
 sine = sin(interval);
 // calculating absolute of sine
 abso = abs(sine);
 printf("sin( %lf ) = %lf \t", interval, abso);
}

printf("\n+++++++\n");
return 0;
}
