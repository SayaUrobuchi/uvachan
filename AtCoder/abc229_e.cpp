#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

int par[N], ans[N];

int find_root(int cur)
{
	if (par[cur] == 0)
	{
		return cur;
	}
	return par[cur] = find_root(par[cur]);
}

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	vector< vector<int> > v(n+1);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	int cnt = 0;
	for (i=n; i>0; i--)
	{
		ans[i] = cnt;
		++cnt;
		for (j=0; j<v[i].size(); j++)
		{
			int t = v[i][j];
			if (t > i)
			{
				int a = find_root(i);
				int b = find_root(t);
				if (a != b)
				{
					par[b] = a;
					--cnt;
				}
			}
		}
	}
	for (i=1; i<=n; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
