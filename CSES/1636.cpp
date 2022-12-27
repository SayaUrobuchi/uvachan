#include <iostream>
using namespace std;

const int M = 1000000007;

int dp[1048576];

int main()
{
	int n, m, i, j, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=m; i++)
		{
			dp[i] = 0;
		}
		dp[0] = 1;
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			for (j=t; j<=m; j++)
			{
				dp[j] = (dp[j]+dp[j-t]) % M;
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}

