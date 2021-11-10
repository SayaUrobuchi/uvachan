#include <iostream>
using namespace std;

const int N = 7;
const int M = 1e9+7;

const char *key = "atcoder";

int dp[131072][16];
char s[131072];

int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		scanf("%s", s);
		dp[0][0] = 1;
		for (i=0; s[i]; i++)
		{
			dp[i+1][0] = dp[i][0];
			for (j=0; j<N; j++)
			{
				dp[i+1][j+1] = dp[i][j+1];
				if (s[i] == key[j])
				{
					dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % M;
				}
			}
		}
		printf("%d\n", dp[n][N]);
	}
	return 0;
}
