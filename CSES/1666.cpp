#include <iostream>
#include <vector>
using namespace std;

vector<int> edg[100005];
bool used[100005];

void dfs(int cur)
{
	int i;
	used[cur] = true;
	for (i=0; i<edg[cur].size(); i++)
	{
		int nxt = edg[cur][i];
		if (!used[nxt])
		{
			dfs(nxt);
		}
	}
}

int main()
{
	int n, m, i, a, b, ans;
	vector<int> lis;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		edg[a].emplace_back(b);
		edg[b].emplace_back(a);
	}
	for (i=1, ans=-1; i<=n; i++)
	{
		if (!used[i])
		{
			dfs(i);
			++ans;
			if (ans)
			{
				lis.emplace_back(i);
			}
		}
	}
	printf("%d\n", ans);
	for (i=0; i<lis.size(); i++)
	{
		printf("1 %d\n", lis[i]);
	}
	return 0;
}
