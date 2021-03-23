#include <stdio.h>
#include <math.h>
int main()
{
  double x;
  printf("Enter x {(x <= -1) || (x > 1)} -> ");
  scanf("%lf", &x);
  if (x <= -1 || x > 1)
  {
    double y = (x-2)*sqrt((1+x)/(x-1));
    double z = log (y*y-1);
    printf ("y(x) = %lf\nz(y) = %lf\n", y, z);
  }
  else
    printf("x value is incorrect!\n");
  return 0;
}
