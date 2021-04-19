#include <stdio.h>
#include <math.h>
int main()
{
		double x = -1;
		double h, y;
		printf("Enter h = ");
		scanf("%lf", &h);
		printf("   x              f(x)\n");
    printf("-------------------------\n");
  	while (x < 2.0 + pow(h, 2))
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
