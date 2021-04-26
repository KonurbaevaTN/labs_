#include <stdio.h>
#include <math.h>
int main()
{
		double x = -1;
		double h, y, n, i;
		printf("Enter h = ");
		scanf("%lf", &h);
		printf("   x              f(x)\n");
    printf("-------------------------\n");
    n = 3.0 / h; i = 0;
  	while (i <= n)
		{
				if (x <= 1 && x >= -1)
				{
						y = exp(-2 * sin(x));
				}
				if (x > 1 && x <= 2)
				{
						y = x * x - cos(x) / sin(x);
				}
				printf("%lf \t %lf \n", x, y);
    		x = x + h;
        i += 1;
		}
  	return 0;
}
