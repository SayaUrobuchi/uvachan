#include <stdio.h>
#include <string.h>

int dp[45];
int ary[45][45];
int num[45];

int main()
{
	int n, m, i, j;
	ary[1][num[1]++] = 0;
	for(i=2; i<=44; i++)
	{
		for(j=1; j*j<i; j++)
		{
			if(!(i % j))
			{
				ary[i][num[i]++] = i - j;
				ary[i][num[i]++] = i - i/j;
			}
		}
		if(j*j==i && !(i % j))
		{
			ary[i][num[i]++] = i - j;
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == m)
		{
			break;
		}
		memset(dp, 0, sizeof(dp));
		dp[m] = 1;
		for(i=m; i>n; i--)
		{
			/*printf("%d: %d\n", i, dp[i]);*/
			for(j=0; j<num[i]; j++)
			{
				dp[ary[i][j]] += dp[i];
				/*printf("%d %d: %d\n", i, j, ary[i][j]);*/
			}
		}
		printf("%d %d %d\n", n, m, dp[n]);
	}
	return 0;
}
