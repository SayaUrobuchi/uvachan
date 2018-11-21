#include <stdio.h>

#define M 1000000007

int dp[1000005][6];
int mx = 1;

int checkRecord(int n) {
	int i, res;
	for (i=mx; i<=n; i++)
	{
		dp[i][0] = ((dp[i-1][0] + dp[i-1][1]) % M + dp[i-1][2]) % M;
		dp[i][1] = dp[i-1][0];
		dp[i][2] = dp[i-1][1];
		dp[i][3] = (((dp[i-1][3] + dp[i-1][4]) % M + dp[i-1][5]) % M + dp[i][0]) % M;
		dp[i][4] = dp[i-1][3];
		dp[i][5] = dp[i-1][4];
	}
	mx = i;
	for (i=0, res=0; i<6; i++)
	{
		res = (res + dp[n][i]) % M;
	}
	return res;
}

int main()
{
	int n;
	dp[0][0] = 1;
	while (scanf("%d", &n) == 1)
	{
		printf("%d\n", checkRecord(n));
	}
	return 0;
}
