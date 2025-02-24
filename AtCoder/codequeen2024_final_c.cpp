#include <iostream>
using namespace std;

const int N = 200005;
const int M = 105;

long long pre[N];
long long dp[N][M];

int main()
{
	int n, m, o, i, j;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<=n; i++)
	{
		for (j=1; j<=m; j++)
		{
			dp[i][j] = 1e18;
		}
	}
	dp[0][0] = 0;
	for (i=1; i<=n; i++)
	{
		int t;
		scanf("%d", &t);
		pre[i] = pre[i-1] + t;
		for (j=1; j<=m&&i>=j*o; j++)
		{
			dp[i][j] = min(dp[i-1][j], dp[i-o][j-1]+pre[i]-pre[i-o]);
		}
	}
	printf("%lld\n", dp[n][m]);
	return 0;
}