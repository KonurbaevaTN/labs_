#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char* argv[])
{
    char str[39] = "Hello45 world6, m4y 32name67 is 142...";
    char *p = str;
    int sum = 0;
    while (*p) {
        while (*p && !isdigit(*p))
            ++p;
        sum += atoi(p);
        while (*p && isdigit(*p))
            ++p;
    }
    printf("Сумма чисел в строке = %d\n", sum);
    return sum;
}