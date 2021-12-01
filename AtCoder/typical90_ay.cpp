#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long ary[64];
vector<long long> v0[64], v1[64];

void dfs(int depth, long long sum, int st, int ed, long long lim, vector<long long> v[])
{
	int i;
	if (sum > lim)
	{
		return;
	}
	v[depth].emplace_back(sum);
	for (i=st; i<ed; i++)
	{
		dfs(depth+1, sum+ary[i], i+1, ed, lim, v);
	}
}

int main()
{
	int n, m, i, j, a, b;
	long long o, ans;
	while (scanf("%d%d%lld", &n, &m, &o) == 3)
	{
		for (i=0; i<n; i++)
		{
			scanf("%lld", &ary[i]);
			v0[i].clear();
			v1[i].clear();
		}
		dfs(0, 0, 0, n>>1, o, v0);
		dfs(0, 0, n>>1, n, o, v1);
		for (i=0, ans=0; i<=m; i++)
		{
			j = m-i;
			sort(v0[i].begin(), v0[i].end());
			sort(v1[j].begin(), v1[j].end(), greater<long long>());
			//printf(".. %d %d: siz %d %d\n", i, j, v0[i].size(), v1[j].size());
			for (a=0, b=0; a<v0[i].size(); a++)
			{
				for (; b<v1[j].size()&&v0[i][a]+v1[j][b]>o; b++);
				ans += v1[j].size() - b;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
