#include <stdio.h>

int main()
{
	long long n;
	while (scanf("%lld", &n) == 1)
	{
		if (n < 10)
		{
			puts("Y");
		}
		else if (n <= 1000)
		{
			puts("X");
		}
		else if (n <= 400*1000)
		{
			puts("UV");
		}
		else if (n <= 700*1000)
		{
			puts("VIS");
		}
		else if (n <= 1e9)
		{
			puts("IR");
		}
		else
		{
			puts("R");
		}
	}
	return 0;
}
