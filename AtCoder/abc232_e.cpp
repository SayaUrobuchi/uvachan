#include <iostream>
using namespace std;

const int XOYO = 0;
const int XXYO = 1;
const int XOYX = 2;
const int XXYX = 3;
const int M = 998244353;

int dp[1000005][4];

int main()
{
	int n, m, k, i, sx, sy, ex, ey, stat;
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	stat = 0;
	if (sx != ex)
	{
		stat |= 1;
	}
	if (sy != ey)
	{
		stat |= 2;
	}
	dp[0][stat] = 1;
	for (i=1; i<=k; i++)
	{
		dp[i][XOYO] = (dp[i-1][XXYO] + dp[i-1][XOYX]) % M;
		
		dp[i][XXYO] = (dp[i-1][XOYO] * (long long)(n-1)) % M;
		dp[i][XXYO] = (dp[i][XXYO] + dp[i-1][XXYO] * (long long)(n-2)) % M;
		dp[i][XXYO] = (dp[i][XXYO] + dp[i-1][XXYX]) % M;
		
		dp[i][XOYX] = (dp[i-1][XOYO] * (long long)(m-1)) % M;
		dp[i][XOYX] = (dp[i][XOYX] + dp[i-1][XOYX] * (long long)(m-2)) % M;
		dp[i][XOYX] = (dp[i][XOYX] + dp[i-1][XXYX]) % M;
		
		dp[i][XXYX] = (dp[i-1][XXYX] * (long long)(n-2+m-2)) % M;
		dp[i][XXYX] = (dp[i][XXYX] + dp[i-1][XOYX] * (long long)(n-1)) % M;
		dp[i][XXYX] = (dp[i][XXYX] + dp[i-1][XXYO] * (long long)(m-1)) % M;
	}
	printf("%d\n", dp[k][XOYO]);
	return 0;
}