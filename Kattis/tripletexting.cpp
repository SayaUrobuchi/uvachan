#include <stdio.h>

char s[1048576];

int main()
{
	int a, b, c, len;
	while (scanf("%s", s) == 1)
	{
		for (len=0; s[len]; len++);
		for (a=0, b=len/3, c=(b<<1); s[c]; a++, b++, c++)
		{
			if (s[a] == s[b] || s[a] == s[c])
			{
				putchar(s[a]);
			}
			else if (s[b] == s[a] || s[b] == s[c])
			{
				putchar(s[b]);
			}
			else
			{
				putchar(s[c]);
			}
		}
		puts("");
	}
	return 0;
}
