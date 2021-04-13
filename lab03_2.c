#include <stdio.h>
#include <math.h>
int main()
{
    double h;
    double i, y;
    printf("Enter h = ");
    scanf("%lf", &h);
    for (i = -1; i <= 2; i += h)
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
    }
    return 0;
}
