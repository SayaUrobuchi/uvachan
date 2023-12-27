#include <iostream>
using namespace std;

const int N = 55;
const int M = 1000000007;

int dp[N][3];

int main()
{
	int n, a, b, c, i;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	dp[1][0] = a;
	dp[1][1] = b;
	dp[1][2] = c;
	for (i=2; i<=n; i++)
	{
		dp[i][0] = (dp[i-1][1]+dp[i-1][2])
					 * (long long)(a) % M;
		dp[i][1] = (dp[i-1][0]+dp[i-1][2])
					 * (long long)(b) % M;
		dp[i][2] = (dp[i-1][0]+dp[i-1][1])
					 * (long long)(c) % M;
	}
	int ans = 0;
	for (i=0; i<3; i++)
	{
		ans = (ans + dp[n][i]) % M;
	}
	printf("%d\n", ans);
	return 0;
}
