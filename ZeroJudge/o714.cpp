#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200005;

int st[N], ed[N];
long long dp[N];
vector<int> v[N];

int main()
{
	int n, m, mod, i, j;
	scanf("%d%d%d", &n, &m, &mod);
	for (i=0; i<n; i++)
	{
		scanf("%d", &st[i]);
	}
	vector<int> ary;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ed[i]);
		ary.emplace_back(ed[i]);
	}
	ary.emplace_back(0);
	sort(ary.begin(), ary.end());
	for (i=0; i<n; i++)
	{
		int id = lower_bound(ary.begin(), ary.end(), ed[i])
				 - ary.begin();
		v[id].emplace_back(st[i]);
	}
	dp[0] = 1;
	for (i=1; i<ary.size(); i++)
	{
		dp[i] = dp[i-1];
		for (j=0; j<v[i].size(); j++)
		{
			int l = v[i][j];
			int lid = lower_bound(ary.begin(), ary.end(), l)
					 - ary.begin();
			dp[i] = (dp[i] + (dp[i-1] - dp[lid-1] + mod) % mod) % mod;
		}
	}
	int ans = 0;
	int aid = lower_bound(ary.begin(), ary.end(), m)
			 - ary.begin();
	if (aid < ary.size() && ary[aid] == m)
	{
		ans = (dp[aid] - dp[aid-1] + mod) % mod;
	}
	printf("%d\n", ans);
	return 0;
}
