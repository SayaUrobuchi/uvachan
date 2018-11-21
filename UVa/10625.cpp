#include <stdio.h>
#include <string.h>

int c[10][127];
char str[1001], ch[10], ary[10];
unsigned long long tbl[10001][127];

int main()
{
	int count, n, m, i, j, k, l;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		memset(c, 0, sizeof(c));
		for(i=0; i<n; i++)
		{
			scanf("%s", str);
			ary[i] = str[0];
			for(j=3; str[j]; j++)
			{
				c[i][str[j]]++;
			}
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%s%d", str, ch, &l);
			memset(tbl, 0, sizeof(tbl));
			for(i=0; str[i]; i++)
			{
				tbl[0][str[i]]++;
			}
			for(i=1; i<=l; i++)
			{
				for(j=33; j<=126; j++)
				{
					tbl[i][j] = tbl[i-1][j];
				}
				for(j=0; j<n; j++)
				{
					for(k=33; k<=126; k++)
					{
						tbl[i][k] += tbl[i-1][ary[j]] * c[j][k];
					}
					tbl[i][ary[j]] -= tbl[i-1][ary[j]];
				}
			}
			printf("%llu\n", tbl[l][ch[0]]);
		}
	}
	return 0;
}
