#include <stdio.h>

char s[1048576];

int main()
{
	int i, a, b;
	while (scanf("%s", s) == 1)
	{
		for (i=0, a=0, b=0; s[i]; i+=2)
		{
			if (s[i] == 'A')
			{
				a += s[i+1]-'0';
			}
			else
			{
				b += s[i+1]-'0';
			}
		}
		puts(a>b?"A":"B");
	}
	return 0;
}
