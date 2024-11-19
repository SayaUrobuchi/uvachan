#include <iostream>
using namespace std;

const int N = 64;

long long dp[N][2];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	dp[0][0] = 1;
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		int b = (t & 1);
		dp[i][0] = dp[i-1][0] + dp[i-1][0^b];
		dp[i][1] = dp[i-1][1] + dp[i-1][1^b];
	}
	printf("%lld\n", dp[n][m]);
	return 0;
}
