#include <stdio.h>
#include <string.h>

int tbl[128];
char s[120000];

int main()
{
	int cas, count, i, p;
	cas = 0;
	scanf("%d", &count);
	gets(s);
	while (count--)
	{
		gets(s);
		memset(tbl, 0, sizeof(tbl));
		p = 0;
		printf("Case %d:", ++cas);
		for (i=0; s[i]; i++)
		{
			if (s[i] == '>')
			{
				p = (p+1) % 100;
			}
			else if (s[i] == '<')
			{
				p = (p+99) % 100;
			}
			else if (s[i] == '+')
			{
				tbl[p] = ((tbl[p]+1) & 255);
			}
			else if (s[i] == '-')
			{
				tbl[p] = ((tbl[p]+255) & 255);
			}
			/*else if (s[i] == '.')
			{
				printf(" %02X", tbl[p]);
			}*/
		}
		for (i=0; i<100; i++)
		{
			printf(" %02X", tbl[i]);
		}
		puts("");
	}
	return 0;
}
