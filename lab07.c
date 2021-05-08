#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int a[][n])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][j] = rand() % 10;
}

void print(int n, int a[][n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
}

void search(int n, int m, int a[][n])
{
    int i, j, s = 0, z;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j || i + 1 == j || i == j + 1)
            {
                s = s + a[i][j];
            }
        }
    }
    if (s > m)
    {
        for (i = 0; i < n - 1; i++)
            for (j = i + 1; j < n; j++)
            {
               z = a[i][j];
               a[i][j] = a[j][i];
               a[j][i] = z;
            }
    }
    else
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
            {
                if (i != j && i + 1 != j && i != j + 1)
                {
                    a[i][j] = 0;
                }
            }
    }
    printf("Ansewr: \n");
    print(n, a);
}

int main()
{
    srand(time(NULL));
    int n, m;
    printf("n -> ");
    scanf("%d", &n);
    printf("m -> ");
    scanf("%d", &m);
    int mas[n][m];
    fill(n, mas);
    print(n, mas);
    search(n, m, mas);
    return 0;
}
