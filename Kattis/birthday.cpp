#include <iostream>
#include <vector>
using namespace std;

const int N = 105;

int cnt;
bool ok;
int id[N];
vector<int> v[N];

int dfs(int cur, int par)
{
	int i;
	id[cur] = cnt++;
	int ret = id[cur];
	for (i=0; i<v[cur].size(); i++)
	{
		int nxt = v[cur][i];
		if (nxt != par)
		{
			if (id[nxt] < 0)
			{
				int r = dfs(nxt, cur);
				ret = min(r, ret);
			}
			else
			{
				ret = min(id[nxt], ret);
			}
		}
	}
	//printf(".. %d => %d, id: %d\n", cur, ret, id[cur]);
	if (ret && ret >= id[cur])
	{
		ok = false;
	}
	return ret;
}

int main()
{
	int n, m, i, a, b;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			v[i].clear();
			id[i] = -1;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		ok = true;
		cnt = 0;
		dfs(0, -1);
		if (!ok || cnt != n)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
