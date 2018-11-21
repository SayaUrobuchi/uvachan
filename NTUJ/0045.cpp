#include <stdio.h>

int list[3], dp[105][105][105], ans, n;
char s[20][105];

int max(int p, int q)
{
	return p>q ? p : q;
}

void lcs()
{
	int i, j, k;
	char *p, *q, *r;
	p = s[list[0]];
	q = s[list[1]];
	r = s[list[2]];
	for(i=0; p[i]; i++)
	{
		for(j=0; q[j]; j++)
		{
			for(k=0; r[k]; k++)
			{
				if(p[i] == q[j] && q[j] == r[k])
				{
					dp[i+1][j+1][k+1] = dp[i][j][k] + 1;
				}
				else
				{
					dp[i+1][j+1][k+1] = max(dp[i][j+1][k+1], max(dp[i+1][j][k+1], dp[i+1][j+1][k]));
				}
			}
		}
	}
	if(ans < dp[i][j][k])
	{
		ans = dp[i][j][k];
	}
}

void dfs(int depth, int last)
{
	int i;
	if(depth == 3)
	{
		lcs();
		return;
	}
	for(i=last; i<n; i++)
	{
		list[depth] = i;
		dfs(depth+1, i+1);
	}
}

int main()
{
	int i;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s", s[i]);
		}
		ans = 0;
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}
