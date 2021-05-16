#include<stdio.h>
//#include<termios.h>
#include<unistd.h>
int getch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}
int main()
{
	int count = 0, hoard = 0, count1 = 0;
	double average = 0.0;
	unsigned char c;
	for (;;)
	{
		c = getch();
		if (c == 0 || c == 224)
		{
			c = getch();
			if (c == 46)
				return 0;
		}
		if (c >= 112 && c <= 123)
		{
			count++;
			printf("Scan code %d: %d\n", count, c);
		}
    else
    {
      count1++;
      printf("Symbol: %d\n", c);
    }
	}
}