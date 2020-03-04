#include<iostream>
using namespace std;

int dp[4096][4096];
char s[1048576];

int main() {
	int n, i, j;
	scanf("%d%s", &n, s);
	dp[n][0] = 1;
	for (i=n-1; i>=0; i--)
	{
		for (j=0; j<=i; j++)
		{
			if (s[n-i] == '>')
			{
				dp[i][j] = (dp[i-1][i-1] - dp[i-1][j] + M) % M;
			}
			else
			{
				dp[i][j] = dp[i-1][i-j];
			}
			if (j)
			{
				dp[i][j] = (dp[i][j] + dp[i][j-1]) % M;
			}
		}
	}
	printf("%d\n", dp[0][0]);
	return 0;
}
