#include <stdio.h>
#include <math.h>
int main()
{
		double x = -1;
		double h, y;
		printf("Enter h = ");
		scanf("%lf", &h);
  	while (x < 2 + h)
		{
				if (x <= 1 && x >= -1)
				{
						y = exp(-2 * sin(x));
				}
				if (x > 1 && x <= 2)
				{
						y = x * x - sin(x) / cos(x);
				}
				printf("%lf \t %lf \n", x, y);
    		x = x + h;
		}
  	return 0;
}
