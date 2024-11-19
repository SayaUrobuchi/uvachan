#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

long long asum, bsum;
int ary[N], bry[N];
bool used[N];
vector<int> v[N];

void dfs(int cur)
{
	int i;
	used[cur] = true;
	asum += ary[cur];
	bsum += bry[cur];
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
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1; i<=n; i++)
	{
		scanf("%d", &bry[i]);
	}
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	bool ok = true;
	for (i=1; i<=n&&ok; i++)
	{
		if (!used[i])
		{
			asum = 0;
			bsum = 0;
			dfs(i);
			if (asum != bsum)
			{
				ok = false;
			}
		}
	}
	puts(ok ? "Yes" : "No");
	return 0;
}
