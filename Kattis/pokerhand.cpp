#include <stdio.h>
#include <string.h>

int tbl[128];
char s[5][128];

int main()
{
	int i, ans;
	while (scanf("%s%s%s%s%s", s, s+1, s+2, s+3, s+4) == 5)
	{
		memset(tbl, 0, sizeof(tbl));
		for (i=0, ans=0; i<5; i++)
		{
			tbl[*s[i]]++;
			if (tbl[*s[i]] > ans)
			{
				ans = tbl[*s[i]];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
