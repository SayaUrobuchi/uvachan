#include <iostream>
using namespace std;

const int N = 100005;
const int M = 1000000007;

int exa[N], exb[N];
long long dp[N][2];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &exa[i]);
	}
	for (i=1; i+1<=n; i++)
	{
		scanf("%d", &exb[i]);
	}
	dp[0][0] = 1;
	for (i=1; i<=n; i++)
	{
		dp[i][0] = (dp[i-1][0] * (exa[i]+exb[i-1])) % M;
		if (exb[i-1] > 0)
		{
			dp[i][0] += (dp[i-1][1] * (exa[i]+exb[i-1]-1)) % M;
		}
		dp[i][1] = ((dp[i-1][0]+dp[i-1][1]) * (exb[i])) % M;
	}
	printf("%d\n", (dp[n][0]+dp[n][1])%M);
	return 0;
}
