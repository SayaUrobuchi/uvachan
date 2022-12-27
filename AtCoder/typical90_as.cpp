#include <iostream>
#include <vector>
using namespace std;

int n, m;
int px[32], py[32];
vector<int> v[32];

bool gameover(int a, int b, long long lim)
{
	long long dx = px[a] - px[b];
	long long dy = py[a] - py[b];
	return dx*dx + dy*dy > lim;
}

bool dfs(int depth, int group, long long lim)
{
	int i, j;
	bool gg;
	if (group > m)
	{
		return false;
	}
	if (depth == n)
	{
		return true;
	}
	if (n-depth <= m-group)
	{
		return true;
	}
	for (j=0; j<group; j++)
	{
		for (i=0, gg=false; i<v[j].size()&&!gg; i++)
		{
			gg = gameover(depth, v[j][i], lim);
		}
		if (!gg)
		{
			v[j].emplace_back(depth);
			gg = dfs(depth+1, group, lim);
			v[j].pop_back();
			if (gg)
			{
				return gg;
			}
		}
	}
	v[group].clear();
	v[group].emplace_back(depth);
	return dfs(depth+1, group+1, lim);
}

int main()
{
	int i;
	long long p, q, mid, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%lld%lld", &px[i], &py[i]);
		}
		for (p=0, q=3e18; p<=q; )
		{
			mid = ((p+q) >> 1);
			v[0].clear();
			v[0].emplace_back(0);
			if (dfs(1, 1, mid))
			{
				ans = mid;
				q = mid - 1;
			}
			else
			{
				p = mid + 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

