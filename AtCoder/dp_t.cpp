#include<iostream>
using namespace std;

const int M = 1000000007;

int dp[4096][4096];
char s[1048576];

int main() {
	int n, i, j;
	scanf("%d%s", &n, s);
	for (i=0; i<n; i++)
	{
		dp[n-1][i] = i+1;
	}
	for (i=n-2; i>=0; i--)
	{
		for (j=0; j<=i; j++)
		{
			if (s[n-i-2] == '>')
			{
				dp[i][j] = (dp[i+1][i+1] - dp[i+1][j] + M) % M;
			}
			else
			{
				dp[i][j] = dp[i+1][j];
			}
			if (j)
			{
				dp[i][j] = (dp[i][j] + dp[i][j-1]) % M;
			}
			//printf("%d %d: %d\n", i, j, dp[i][j]);
		}
	}
	printf("%d\n", dp[0][0]);
	return 0;
}
