#include <stdio.h>

char s[128];

int main()
{
	int i;
	while (scanf("%s", s) == 1)
	{
		for (i=0; s[i+1]; i++)
		{
			if (s[i] == s[i+1] && s[i] == 's')
			{
				break;
			}
		}
		puts(s[i+1]?"hiss":"no hiss");
	}
	return 0;
}
