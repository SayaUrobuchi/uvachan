#include <iostream>
using namespace std;

long long dp[1048576][4];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, i, j, t;
	while (cin >> n)
	{
		dp[0][1] = dp[0][2] = dp[0][3] = 1e18;
		for (i=1; i<=n; i++)
		{
			dp[i][0] = 1e18;
			for (j=1; j<=3; j++)
			{
				cin >> t;
				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + t;
			}
		}
		cout << dp[n][3] << "\n";
	}
	return 0;
}
