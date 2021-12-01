#include <iostream>
#include <vector>
using namespace std;

const int N = 131072;

long long cnt[N], root[N], ans[N];
vector<int> v[N];

void recurs(int cur, int par)
{
	int i, nxt;
	long long t, u;
	cnt[cur] = 1;
	root[cur] = 0;
	ans[cur] = 0;
	for (i=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		if (nxt != par)
		{
			recurs(nxt, cur);
			cnt[cur] += cnt[nxt];
			root[cur] += root[nxt] + cnt[nxt];
			ans[cur] += ans[nxt];
		}
	}
	for (i=0, t=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		if (nxt != par)
		{
			u = root[nxt] + cnt[nxt];
			t += u + (root[cur]-u) * cnt[nxt];
		}
	}
	ans[cur] += t;
	//printf("%d: cnt %lld, root %lld, ans %lld\n", cur, cnt[cur], root[cur], ans[cur]);
}

int main()
{
	int n, i, a, b;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
		}
		for (i=1; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		recurs(1, -1);
		printf("%lld\n", ans[1]);
	}
	return 0;
}
