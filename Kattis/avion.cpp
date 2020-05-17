#include <stdio.h>
#include <string.h>

char s[8][16];

int main()
{
	int i, j, len, first, fbi;
	while (scanf("%s", s[0]) == 1)
	{
		for (i=1; i<5; i++)
		{
			scanf("%s", s[i]);
		}
		for (i=0, first=1; i<5; i++)
		{
			for (j=0, len=strlen(s[i]), fbi=0; j+2<len; j++)
			{
				if (strncmp(s[i]+j, "FBI", 3) == 0)
				{
					fbi = 1;
					break;
				}
			}
			if (fbi)
			{
				if (!first)
				{
					putchar(' ');
				}
				first = 0;
				printf("%d", i+1);
			}
		}
		if (first)
		{
			puts("HE GOT AWAY!");
		}
		else
		{
			puts("");
		}
	}
	return 0;
}
