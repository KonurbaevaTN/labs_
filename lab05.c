#include <stdio.h>
int nod(int a, int b)
{
     if (b == 0)
        return a;
     else
        return nod (b, a % b);
}
void SearchNod(int a, int b)
{
    int NOD = 1, i;
    for(i = 1; i <= a; i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            NOD = i;
        }
    }
    printf(" Cycle: %d \n ", NOD);
}
int main(void)
{
    int a, b;
    printf (" NOD of a and b -> ") ;
    scanf("%d %d", &a, &b);
    SearchNod(a, b);
    printf ("Recursion: %d \n ", nod(a, b));
    return 0;
}
