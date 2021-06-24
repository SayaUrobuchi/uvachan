#include <iostream>
#include <vector>

int ucnt, used[2048];
int qq[2048];
std::vector<int> v[2048];

int bfs(int st)
{
	int i, j, k, cur, nxt;
	qq[0] = st;
	used[st] = ++ucnt;
	for (i=0, j=1; i<j; i++)
	{
		cur = qq[i];
		for (k=0; k<v[cur].size(); k++)
		{
			nxt = v[cur][k];
			if (used[nxt] != ucnt)
			{
				used[nxt] = ucnt;
				qq[j] = nxt;
				++j;
			}
		}
	}
	return j;
}

int main()
{
	int n, m, a, b, i, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
		}
		for (i=1, ans=0; i<=n; i++)
		{
			ans += bfs(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}
