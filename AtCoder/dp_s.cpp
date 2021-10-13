#include <iostream>
using namespace std;

const int M = 1000000007;

int dp[16384][128];
char buf[16384];

int main()
{
	int n, m, i, j, k, sum, ans;
	while (scanf("%s%d", buf, &m) == 2)
	{
		for (n=0; buf[n]; n++);
		dp[0][0] = 1;
		for (i=1; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				dp[i][j] = dp[i-1][j];
				for (k=1; k<10; k++)
				{
					dp[i][j] = (dp[i][j] + dp[i-1][(j-k%m+m)%m]) % M;
				}
			}
		}
		for (i=0, sum=0, ans=0; i<n; sum=(sum+buf[i]-'0')%m, i++)
		{
			for (j=0; j+'0'<buf[i]; j++)
			{
				ans = (ans + dp[n-i-1][(m-(sum+j)%m)%m]) % M;
			}
		}
		if (sum)
		{
			ans = (ans + M - 1) % M;
		}
		printf("%d\n", ans);
	}
	return 0;
}
