#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int m, int a[][m])
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            a[i][j] = rand() % 10;
}

void print(int n, int m, int a[][m])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
}

void search(int n, int m, int b, int a[][m])
{
    int i, j, s = 0;
    int k[m][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == j || i + 1 == j || i == j + 1)
            {
                s = s + a[i][j];
            }
        }
    }
    if (s > b)
    {
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
            {
               k[i][j] = a[j][i];
            }


        printf("Ansewr: \n");
        print(m, n, k);
    }
    else
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                if (i != j && i + 1 != j && i != j + 1)
                {
                    a[i][j] = 0;
                }
            }
        printf("Ansewr: \n");
        print(n, m, a);
    }
}

int main()
{
    srand(time(NULL));
    int n, m, b;
    printf("n -> ");
    scanf("%d", &n);
    printf("m -> ");
    scanf("%d", &m);
    printf("b -> ");
    scanf("%d", &b);
    int mas[n][m];
    fill(n, m, mas);
    print(n, m, mas);
    search(n, m, b, mas);
    return 0;
}
