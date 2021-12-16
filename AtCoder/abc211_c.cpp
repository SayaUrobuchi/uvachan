#include <iostream>
using namespace std;

const char *key = ":chokudai";
const int N = 8;
const int M = 1000000007;

int dp[131072][16];
char s[131072];

int main()
{
	int i, j;
	while (scanf("%s", s+1) == 1)
	{
		dp[0][0] = 1;
		for (i=1; s[i]; i++)
		{
			dp[i][0] = 1;
			for (j=1; j<=N; j++)
			{
				dp[i][j] = dp[i-1][j];
				if (s[i] == key[j])
				{
					dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % M;
				}
			}
		}
		printf("%d\n", dp[i-1][N]);
	}
	return 0;
}
