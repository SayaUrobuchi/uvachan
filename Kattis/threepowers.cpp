#include <iostream>

using ii = __int128_t;

void print(ii t)
{
	if (t >= 10)
	{
		print(t/10);
	}
	putchar(t%10 + '0');
}

int main()
{
	unsigned long long n;
	ii v;
	bool first;
	while (scanf("%llu", &n) == 1)
	{
		if (n-- == 0)
		{
			break;
		}
		putchar('{');
		v = 1;
		for (first=true; n; n>>=1)
		{
			if (n & 1)
			{
				if (!first)
				{
					putchar(',');
				}
				putchar(' ');
				print(v);
				first = false;
			}
			v *= 3;
		}
		puts(" }");
	}
	return 0;
}
