#include <iostream>
#include <algorithm>
using namespace std;

const int M = 998244353;

pair<int, int> ary[5050];
int dp[5050];

int main()
{
	int n, m, i, j, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, m=0; i<n; i++)
		{
			scanf("%d", &ary[i].first);
			m = max(ary[i].first, m);
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i].second);
		}
		sort(ary, ary+n);
		dp[0] = 1;
		for (i=1; i<=m; i++)
		{
			dp[i] = 0;
		}
		for (i=0, ans=0; i<n; i++)
		{
			for (j=m; j>=ary[i].second; j--)
			{
				dp[j] = (dp[j]+dp[j-ary[i].second]) % M;
				if (j <= ary[i].first)
				{
					ans = (ans+dp[j-ary[i].second]) % M;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

