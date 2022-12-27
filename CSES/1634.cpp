#include <iostream>
using namespace std;

int dp[1048576];

int main()
{
	int n, m, i, j, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=m; i++)
		{
			dp[i] = 2e9;
		}
		dp[0] = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			for (j=t; j<=m; j++)
			{
				dp[j] = min(dp[j], dp[j-t]+1);
			}
		}
		if (dp[m] > m)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n", dp[m]);
		}
	}
	return 0;
}

