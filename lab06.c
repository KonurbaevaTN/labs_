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

void revers(int n, int b, int a[])
{
    int i, j, c, t, k;
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
	
    if (j == n){
        for (i = 0; i < n / 2; i++)
        {
            c = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = c;
        }
    }
    else
    {
        for (i = 0; i < j / 2; i++)
        {
            c = a[i];
            a[i] = a[j - i - 1];
            a[j - i - 1] = c;
        }
		
		for(i = 0; i < (n - j - 1)/ 2; i++)
		{
			c = a[i + j + 1];
			a[i + j + 1] = a[n - i - 1];
            a[n - i - 1] = c;
		}
    }
}

int main()
{
    srand(time(NULL));
    int n, b, j;
    printf("n -> ");
    scanf("%d", &n);
    int mas[n];
    fill(n, mas);
    print(n, mas);
    printf("b -> ");
    scanf("%d", &b);
    revers(n, b, mas);
    print(n, mas);
    return 0;
}
