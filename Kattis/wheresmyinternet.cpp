#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

bool conn[N];
vector<int> v[N];

void dfs(int cur)
{
	int i;
	conn[cur] = true;
	for (i=0; i<v[cur].size(); i++)
	{
		int nxt = v[cur][i];
		if (!conn[nxt])
		{
			dfs(nxt);
		}
	}
}

int main()
{
	int n, m, i, a, b;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1);
	int all_conn = true;
	for (i=1; i<=n; i++)
	{
		if (!conn[i])
		{
			printf("%d\n", i);
			all_conn = false;
		}
	}
	if (all_conn)
	{
		puts("Connected");
	}
	return 0;
}
