#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char str[37] = "Hello world6, m4y 32name67 is 142...";
    int sum = 0;
    for(int i = 0; i < 37; i++)
    {
        if (isdigit(str[i]))
          sum += (int)str[i] - 48;
    }
    printf("Answer = %d\n", sum);
    return 0;
}
