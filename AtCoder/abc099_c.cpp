#include <iostream>
using namespace std;

const int N = 100005;

long long dp[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	dp[0] = 0;
	for (i=1; i<=n; i++)
	{
		dp[i] = dp[i-1] + 1;
		for (j=6; j<=i; j*=6)
		{
			dp[i] = min(dp[i], dp[i-j]+1);
		}
		for (j=9; j<=i; j*=9)
		{
			dp[i] = min(dp[i], dp[i-j]+1);
		}
	}
	printf("%lld\n", dp[n]);
	return 0;
}
