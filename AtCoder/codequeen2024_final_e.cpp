#include <iostream>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

const int N = 5005;

int ary[N];
ppp bry[N];
int dp[N][N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary+1, ary+n+1);
	for (i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		bry[i] = make_pair(a, make_pair(b, c));
	}
	sort(bry+1, bry+m+1);
	memset(dp, -1, sizeof(dp));
	for (i=0; i<=m; i++)
	{
		dp[0][i] = 0;
	}
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=m; j++)
		{
			int rk, cnt, cost;
			forward_as_tuple(rk, tie(cnt, cost)) = bry[j];
			dp[i][j] = dp[i][j-1];
			if (ary[i] <= rk)
			{
				int t = max(0, i-cnt);
				if (dp[t][j-1] >= 0)
				{
					if (dp[i][j] < 0 || dp[i][j] > dp[t][j-1]+cost)
					{
						dp[i][j] = dp[t][j-1]+cost;
					}
				}
			}
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}
