#define M 1000000007

int dp[100005][6];

int checkRecord(int n) {
	int i;
	dp[0][0] = 1;
	for (i=1; i<=n; i++)
	{
		dp[i][0] = ((dp[i-1][0] + dp[i-1][1]) % M + dp[i-1][2]) % M;
		dp[i][1] = dp[i-1][0];
		dp[i][2] = dp[i-1][1];
		dp[i][3] = (((dp[i-1][3] + dp[i-1][4]) % M + dp[i-1][5]) % M + dp[i][0]) % M;
		dp[i][4] = dp[i-1][3];
		dp[i][5] = dp[i-1][4];
	}
	for (i=1; i<6; i++)
	{
		dp[n][0] = (dp[n][0] + dp[n][i]) % M;
	}
	return dp[n][0];
}
