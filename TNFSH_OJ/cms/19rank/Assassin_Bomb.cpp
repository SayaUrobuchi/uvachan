#include <stdio.h>

char str[1000005];

int main()
{
	long long a, b;
	char *ptr;
	while (scanf("%s%lld", str, &b) == 2)
	{
		ptr = str;
		if (*ptr == '-')
		{
			++ptr;
		}
		if (b < 0)
		{
			b = -b;
		}
		for (a=0; *ptr; ptr++)
		{
			a *= 10;
			a += (*ptr - '0');
			a %= b;
		}
		puts(a ? "No" : "Yes");
	}
	return 0;
}
