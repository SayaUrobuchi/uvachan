#include <stdio.h>

char s[128];

int main()
{
	int i;
	while (scanf("%s", s) == 1)
	{
		for (i=0; s[i]; i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				putchar(s[i]);
			}
		}
		puts("");
	}
	return 0;
}
