#include <stdio.h>
#include <math.h>
int main()
{
    double h;
    double i = -1.0, y;
    printf("Enter h = ");
    scanf("%lf", &h);
    printf("   x              f(x)\n");
    printf("-------------------------\n");
    long int k = -1.0, n = 3 / h;
    for (k = -1; k < n; k++)
    {
        if (i <= 1 && i >= -1)
        {
            y = exp(-2 * sin(i));
        }
        if (i > 1 && i <= 2)
        {
            y = i * i - sin(i) / cos(i);
        }
        printf("%lf \t %lf \n", i, y);
        i += h;
    }
    return 0;
}
