#include <iostream>
using namespace std;

const int M = 1000000007;
const int N = 1000000;

int dp[N+8], dp_w[N+8], dp_s[N+8], dpp[N+8];

int main()
{
	int count, n, i, j, k, t;
	dp[0] = 0;
	dpp[0] = 0;
	dp_w[0] = 1;
	dp_s[0] = 1;
	for (i=1; i<=N; i++)
	{
		dp_w[i] = (dp_s[i-1] + dpp[i-1]) % M;
		dp[i] = (((long long)dp[i-1]<<2)+dp_w[i-1]) % M;
		dpp[i] = (dpp[i-1] + dp[i]) % M;
		dp_s[i] = (dp_s[i-1] + dp_w[i]) % M;
		//printf("%d => %d+%d=%d\n", i, dp[i], dp_w[i], dp[i]+dp_w[i]);
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		printf("%d\n", (dp_w[n]+dp[n])%M);
	}
	return 0;
}

