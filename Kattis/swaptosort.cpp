#include <iostream>
#include <vector>
using namespace std;

const int N = 1000005;

int grp[N];
vector<int> edg[N];

void dfs(int cur, int gid)
{
	int i;
	grp[cur] = gid;
	for (i=0; i<edg[cur].size(); i++)
	{
		int nxt = edg[cur][i];
		if (grp[nxt] == 0)
		{
			dfs(nxt, gid);
		}
	}
}

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edg[a].emplace_back(b);
		edg[b].emplace_back(a);
	}
	for (i=1, j=1; i<=n; i++)
	{
		if (grp[i] == 0)
		{
			dfs(i, j);
			j++;
		}
	}
	bool gg = false;
	for (i=1; i<=n&&!gg; i++)
	{
		int counter = n - i + 1;
		if (grp[i] != grp[counter])
		{
			gg = true;
		}
	}
	puts(gg?"No":"Yes");
	return 0;
}
