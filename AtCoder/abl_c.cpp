#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;

bool used[N];
vector<int> v[N];

void dfs(int cur)
{
	int i;
	used[cur] = true;
	for (i=0; i<v[cur].size(); i++)
	{
		int nxt = v[cur][i];
		if (!used[nxt])
		{
			dfs(nxt);
		}
	}
}

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	int ans = 0;
	for (i=1; i<=n; i++)
	{
		if (!used[i])
		{
			++ans;
			dfs(i);
		}
	}
	printf("%d\n", ans-1);
	return 0;
}
