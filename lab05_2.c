#include<stdio.h>
int main()
{
    int a, b, i, m;
    float z;
    printf (" NOD of a and b -> ") ;
    scanf("%d %d",&a,&b);
    if (a < b)
        m = a;
    else
        m = b;
    for (i = 1; i <= m; i++)
    {
        if (a % i == 0 && b % i == 0)
            z = i;
    }
    printf("NOD(a,b) = %f", z);
}
