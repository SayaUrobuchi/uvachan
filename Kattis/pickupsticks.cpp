#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, a, b, i, j;
	scanf("%d%d", &n, &m);
	vector<int> deg(n+1);
	vector<vector<int> > conn(n+1);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		++deg[b];
		conn[a].emplace_back(b);
	}
	vector<int> v;
	for (i=1; i<=n; i++)
	{
		if (deg[i] == 0)
		{
			v.emplace_back(i);
		}
	}
	for (i=0; i<v.size(); i++)
	{
		int cur = v[i];
		for (j=0; j<conn[cur].size(); j++)
		{
			int nxt = conn[cur][j];
			--deg[nxt];
			if (deg[nxt] == 0)
			{
				v.emplace_back(nxt);
			}
		}
	}
	if (v.size() != n)
	{
		puts("IMPOSSIBLE");
	}
	else
	{
		for (i=0; i<v.size(); i++)
		{
			printf("%d\n", v[i]);
		}
	}
	return 0;
}
