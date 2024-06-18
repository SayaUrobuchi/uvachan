#include <iostream>
using namespace std;

int dp[15][2];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	dp[0][1] = 1;
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		for (j=1; j<=3; j++)
		{
			if ((t+j) & 1)
			{
				dp[i][0] += dp[i-1][0];
				dp[i][1] += dp[i-1][1];
			}
			else
			{
				dp[i][0] += dp[i-1][0] + dp[i-1][1];
			}
		}
	}
	printf("%d\n", dp[n][0]);
	return 0;
}
