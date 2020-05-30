#include <stdio.h>

char cmd[8], s[256];

int main()
{
	int i, j;
	while (scanf("%s%s", cmd, s) == 2)
	{
		if (*cmd == 'E')
		{
			for (i=0; s[i]; i=j)
			{
				for (j=i+1; s[j]&&s[j]==s[i]; j++);
				printf("%c%d", s[i], j-i);
			}
			puts("");
		}
		else
		{
			for (i=0; s[i]; i+=2)
			{
				for (j=s[i+1]-'0'; j; j--)
				{
					printf("%c", s[i]);
				}
			}
			puts("");
		}
	}
	return 0;
}
