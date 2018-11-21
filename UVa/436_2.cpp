#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double map[30][30], dp[30][30];
char ary[30][101];

int main()
{
	int cas, n, m, i, j, k, l, t1, t2;
	double temp;
	char s1[101], s2[101];
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", ary[i]);
		}
		memset(dp, 0, sizeof(dp));
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%lf%s", s1, &temp, s2);
			for(i=0, j=0; i<n; i++)
			{
				if(!strcmp(ary[i], s1))
				{
					t1 = i;
					j++;
					if(j == 2)
					{
						break;
					}
				}
				if(!strcmp(ary[i], s2))
				{
					t2 = i;
					j++;
					if(j == 2)
					{
						break;
					}
				}
			}
			dp[t1][t2] = temp;
		}
		for(j=0; j<n&&m; j++)
		{
			for(k=0; k<n&&m; k++)
			{
				for(l=0; l<n; l++)
				{
					if(dp[k][l] < dp[k][j] * dp[j][l])
					{
						dp[k][l] = dp[k][j] * dp[j][l];
					}
				}
				if(dp[k][k] > 1)
				{
					m = 0;
					break;
				}
			}
		}
		if(m)
		{
			printf("Case %d: No\n", ++cas);
		}
		else
		{
			printf("Case %d: Yes\n", ++cas);
		}
	}
	return 0;
}
