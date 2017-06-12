#include <stdio.h>
#include <string.h>

int dp[105][205];
char map[105][205];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
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
	int cas, n, i, j, l, r, ans;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		gets(map[0]);
		memset(dp, 0, sizeof(dp));
		for(i=0, l=0, r=n+n-1, ans=0; i<n; i++, l++, r--)
		{
			gets(map[i]);
			for(j=l; j<r; j+=2)
			{
				if(map[i][j] == '-')
				{
					if(!i || map[i-1][j] != '-')
					{
						dp[i][j] = 1;
					}
					else
					{
						dp[i][j] = min(dp[i-1][j-1], dp[i-1][j+1]) + 1;
					}
					ans = max(ans, dp[i][j]);
				}
			}
		}
		memset(dp, 0, sizeof(dp));
		for(i=n-1, l--, r++; i>-1; i--, l--, r++)
		{
			for(j=l+1; j<r; j+=2)
			{
				if(map[i][j] == '-')
				{
					if(i != n-1 && map[i+1][j] == '-')
					{
						dp[i][j] = min(dp[i+1][j-1], dp[i+1][j+1]) + 1;
					}
					else
					{
						dp[i][j] = 1;
					}
				}
				ans = max(ans, dp[i][j]);
			}
		}
		printf("Triangle #%d\nThe largest triangle area is %d.\n\n", ++cas, ans*ans);
	}
	return 0;
}
