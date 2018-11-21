#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double map[30][30], dp[30][30][31];
char ary[30][101];

int comp(const void *p, const void *q)
{
	return strcmp((char*)p, (char*)q);
}

int bisearch(char *str, int left, int right)
{
	int center, cmp;
	center = left + right;
	center /= 2;
	cmp = strcmp(ary[center], str);
	if(!cmp)
	{
		return center;
	}
	else if(cmp > 0)
	{
		return bisearch(str, left, center-1);
	}
	return bisearch(str, center+1, right);
}

int main()
{
	int cas, n, m, i, j, k, l;
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
		qsort(ary, n, sizeof(ary[0]), comp);
		memset(map, 0, sizeof(map));
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%lf%s", s1, &temp, s2);
			map[bisearch(s1, 0, n-1)][bisearch(s2, 0, n-1)] = temp;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				dp[i][j][0] = map[i][j];
			}
		}
		for(i=1; i<=n; i++)
		{
			for(j=0; j<n; j++)
			{
				for(k=0; k<n; k++)
				{
					dp[j][k][i] = -1;
					for(l=0; l<n; l++)
					{
						if(map[l][k] > 0 && dp[j][l][i-1] > 0)
						{
							if(dp[j][k][i] < 0 || dp[j][k][i] < dp[j][l][i-1] * map[l][k])
							{
								dp[j][k][i] = dp[j][l][i-1] * map[l][k];
							}
						}
					}
				}
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(dp[i][i][j] > 1)
				{
					break;
				}
			}
			if(j <= n)
			{
				break;
			}
		}
		if(i < n)
		{
			printf("Case %d: Yes\n", ++cas);
		}
		else
		{
			printf("Case %d: No\n", ++cas);
		}
	}
	return 0;
}
