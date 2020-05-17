#include <stdio.h>

char s[1048576];

int main()
{
	int i;
	while (scanf("%s", s) == 1)
	{
		for (i=0; s[i]; i++)
		{
			if (!i || s[i]!=s[i-1])
			{
				putchar(s[i]);
			}
		}
		puts("");
	}
	return 0;
}
