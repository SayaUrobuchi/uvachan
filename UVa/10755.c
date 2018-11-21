#include <stdio.h>
#include <string.h>

char chk[20][20][20][20][20][20], ary[20][20][20], dp[20][20][20][20][20][20];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int dfs(int p, int q, int r, int n, int m, int o)
{
	int i, j, k, maximum, temp;
	if(chk[p][q][r][n][m][o])
	{
		return dp[p][q][r][n][m][o];
	}
	maximum = ary[n][m][o];
	if(p)
	{
		maximum -= ary[p-1][m][o];
	}
	if(q)
	{
		maximum -= ary[n][q-1][o];
	}
	if(r)
	{
		maximum -= ary[n][m][r-1];
	}
	if(p && q)
	{
		maximum += ary[p-1][q-1][o];
	}
	if(p && r)
	{
		maximum += ary[p-1][m][r-1];
	}
	if(q && r)
	{
		maximum += ary[n][q-1][r-1];
	}
	if(p && q && r)
	{
		maximum -= ary[p-1][q-1][r-1];
	}
	if(p < n)
	{
		maximum = max(dfs(p+1, q, r, n, m, o), maximum);
	}
	if(q < m)
	{
		maximum = max(dfs(p, q+1, r, n, m, o), maximum);
	}
	if(r < o)
	{
		maximum = max(dfs(p, q, r+1, n, m, o), maximum);
	}
	if(n > p)
	{
		maximum = max(dfs(p, q, r, n-1, m, o), maximum);
	}
	if(m > q)
	{
		maximum = max(dfs(p, q, r, n, m-1, o), maximum);
	}
	if(o > r)
	{
		maximum = max(dfs(p, q, r, n, m, o-1), maximum);
	}
	chk[p][q][r][n][m][o] = 1;
	return dp[p][q][r][n][m][o] = maximum;
}

int main()
{
	int count, i, j, k, n, m, o;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		memset(chk, 0, sizeof(chk));
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				for(k=0; k<o; k++)
				{
					scanf("%d", &ary[i][j][k]);
					if(i)
					{
						ary[i][j][k] += ary[i-1][j][k];
					}
					if(j)
					{
						ary[i][j][k] += ary[i][j-1][k];
					}
					if(k)
					{
						ary[i][j][k] += ary[i][j][k-1];
					}
					if(i && j)
					{
						ary[i][j][k] -= ary[i-1][j-1][k];
					}
					if(i && k)
					{
						ary[i][j][k] -= ary[i-1][j][k-1];
					}
					if(j && k)
					{
						ary[i][j][k] -= ary[i][j-1][k-1];
					}
					if(i && j && k)
					{
						ary[i][j][k] += ary[i-1][j-1][k-1];
					}
				}
			}
		}
		printf("%d\n", dfs(0, 0, 0, n-1, m-1, o-1));
	}
	return 0;
}
