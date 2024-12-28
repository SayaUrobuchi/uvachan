/*
	ID: sa072682
	LANG: C
	TASK: stamps
*/
#include <stdio.h>

int dp[2000001];

int main()
{
	int n, m, i, j, c;
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(i=0; i<m; i++)
	{
		scanf("%d", &c);
		dp[c] = 1;
		for(j=c+1; j<2000001; j++)
		{
			if(dp[j-c] && dp[j-c] < n)
			{
				if(!dp[j] || dp[j] > dp[j-c] + 1)
				{
					dp[j] = dp[j-c] + 1;
				}
			}
		}
	}
	for(i=1; i<2000001; i++)
	{
		if(!dp[i])
		{
			break;
		}
	}
	printf("%d\n", i-1);
	scanf(" ");
	return 0;
}
