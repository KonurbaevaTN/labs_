#include<stdio.h>
void SearchNod(int a, int b)
{
    int NOD=1,i;
    for(i=1;i<=a;i++)
    {
        if(a % i == 0 && b % i == 0)
        {
            NOD=i;
        }
    }
    printf("NOD(a,b) = %d",NOD);
}
int main(void)
{
    int a,b;
    printf (" NOD of a and b -> ") ;
    scanf("%d %d",&a,&b);
    SearchNod(a,b);
}
