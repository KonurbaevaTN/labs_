#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand() % 20;
}

void print(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        printf("%4d ", a[i]);
    printf("\n");
}

int search(int n, int b, int a[])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (a[i] == b)
        {
            j = i;
            break;
        }
        else
            j = n;
    }
    if (j == n)
    {
        for (i = n; i > 0; --i)
            printf("%4d ", a[i - 1]);
        printf("\n");
    }
    else
    {
        for (i = j; i > 0; --i)
           printf("%4d ", a[i - 1]);
        for (i = j; i < n; i++)
           printf("%4d ", a[i]);
    }
}

int main()
{
    srand(time(NULL));
    int n, b;
    printf("n -> ");
    scanf("%d", &n);
    int mas[n];
    fill(n, mas);
    print(n, mas);
    printf("b -> ");
    scanf("%d", &b);
    search(n, b, mas);
    return 0;
}
