#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = (1 << 16);

bool used[N];
vector<int> ary;
vector<int> v[N];

inline int enc(int x, int y)
{
	return (x << 7) | y;
}

bool dfs(int cur)
{
	int i;
	used[cur] = true;
	bool ok = (v[cur].size() == 2);
	for (i=0; i<v[cur].size(); i++)
	{
		int nxt = v[cur][i];
		if (!used[nxt])
		{
			ok &= dfs(nxt);
		}
	}
	return ok;
}

int main()
{
	int i, x0, x1, y0, y1;
	while (scanf(" ( %d , %d ) , ( %d , %d ) ;", &x0, &y0, &x1, &y1) == 4)
	{
		int a = enc(x0, y0);
		int b = enc(x1, y1);
		ary.emplace_back(a);
		ary.emplace_back(b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	sort(ary.begin(), ary.end());
	ary.resize(distance(ary.begin(), unique(ary.begin(), ary.end())));
	int ans = 0;
	int total = 0;
	for (i=0; i<ary.size(); i++)
	{
		if (!used[ary[i]])
		{
			bool res = dfs(ary[i]);
			ans += res;
			++total;
		}
	}
	printf("%d %d\n", total, ans);
	return 0;
}
