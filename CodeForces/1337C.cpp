#include <stdio.h>
#include <vector>
#include <algorithm>

const int N = 200005;

int pqn;
int pq[N];
std::vector<int> v[N];

bool comp(int p, int q)
{
	return p > q;
}

int dfs(int depth, int par, int cur)
{
	int i, nxt, cnt;
	cnt = 1;
	for (i=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		if (nxt != par)
		{
			cnt += dfs(depth+1, cur, nxt);
		}
	}
	pq[pqn++] = depth - (cnt-1);
	return cnt;
}

int main()
{
	int n, m, i, p, q;
	long long ans;
	scanf("%d%d", &n, &m);
	for (i=1; i<n; i++)
	{
		scanf("%d%d", &p, &q);
		v[p].emplace_back(q);
		v[q].emplace_back(p);
	}
	pqn = 0;
	dfs(0, -1, 1);
	std::sort(pq, pq+pqn, comp);
	for (i=0, ans=0; i<m; i++)
	{
		ans += pq[i];
	}
	printf("%lld\n", ans);
	return 0;
}
