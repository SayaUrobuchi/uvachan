#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, pair<int, int> >;

const int LIM = 5000;

pp ary[8192];
long long dp[8192][8192];

int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d%d%d", &ary[i].first, &ary[i].second.first, &ary[i].second.second);
		}
		sort(ary+1, ary+n+1);
		dp[0][0] = 0;
		for (i=1; i<=n; i++)
		{
			for (j=0; j<=LIM; j++)
			{
				dp[i][j] = max(dp[i-1][j], j?dp[i][j-1]:0);
				if (j <= ary[i].first && j-ary[i].second.first >= 0)
				{
					dp[i][j] = max(dp[i][j], dp[i-1][j-ary[i].second.first]+ary[i].second.second);
				}
			}
		}
		printf("%lld\n", dp[n][LIM]);
	}
	return 0;
}
