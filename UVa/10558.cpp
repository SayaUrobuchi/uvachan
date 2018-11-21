#include <stdio.h>
#include <string.h>

int line[105], count[105][105], dp[105][105], last[105][105];
char map[105][105];

void recursion(int now, int c)
{
	if(now == 1 || !c)
	{
		return;
	}
	recursion(last[now][c], c-1);
	printf(" %d", now);
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, m, i, j, k, l, p, q, c, ans;
	while(scanf("%d", &n) == 1)
	{
		if(n == -1)
		{
			break;
		}
		memset(map, 0, sizeof(map));
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &j, &k);
			map[j][k] = 1;
		}
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d", &line[i]);
		}
		scanf("%d", &c);
		c--;
		memset(dp, 0, sizeof(dp));
		memset(count, 0, sizeof(count));
		for(i=1; i<100; i++)
		{
			for(j=line[0], k=1, l=0; j<=line[m-1]; j++)
			{
				if(line[k] == j)
				{
					count[i][k] = count[i-1][k] + l;
					k++;
					l = 0;
				}
				if(map[j][i])
				{
					l = 1;
				}
			}
			if(i > 1)
			{
				dp[i][1] = 0;
				for(j=1, l=0; j<m; j++)
				{
					if(count[i-1][j] - count[0][j])
					{
						dp[i][1]++;
					}
					if(count[i-1][j] - count[i-2][j])
					{
						l++;
					}
				}
				for(j=2; j<c; j++)
				{
					dp[i][j] = dp[i-1][j-1] + l;
					last[i][j] = i - 1;
				}
				for(j=i-2; j; j--)
				{
					for(k=1, l=0; k<m; k++)
					{
						if(count[i-1][k] - count[j-1][k])
						{
							l++;
						}
					}
					for(k=2; k<c; k++)
					{
						if(dp[j][k-1] + l > dp[i][k])
						{
							dp[i][k] = dp[j][k-1] + l;
							last[i][k] = j;
						}
					}
				}
			}
		}
		c--;
		for(i=99, ans=0, k=99; i; i--)
		{
			for(j=1, l=0; j<m; j++)
			{
				if(count[99][j] - count[i-1][j])
				{
					l++;
				}
			}
			if(dp[i][c] + l > ans)
			{
				ans = dp[i][c] + l;
				k = i;
			}
		}
		printf("%d 1", c+2);
		recursion(k, c);
		printf(" 100\n");
	}
	return 0;
}
