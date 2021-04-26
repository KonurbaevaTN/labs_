#include <math.h>
#include <stdio.h>
int main()
{
    double xi, Integral, Integral2, h, y, x, e, d = 3.0;
    int n = 2;
    printf("E -> ");
    scanf("%lf", &e);
    while (d >= e)
    {
        Integral2 = Integral;
        Integral = 0;
        h = 3.0 / n;
        for (int i = -1; i < n; i++)
        {
            xi = -1 + i * h;
            x = xi + h / 2.0;
            if (x > 1.0)
                y = x * x - cos(x) / sin(x);
            else
                y = exp(-2 * sin(x));
            Integral = Integral + y;
        }
        Integral = h * Integral;
        n = n * 2;
        d = fabs(Integral - Integral2) / 3.0;
		printf("\nI = %.5lf", Integral);
		printf("\nd = %.5lf", d);
		printf("\nn = %d\n", n);
    }
    printf("\nAns = %.5lf", Integral);
    
 }