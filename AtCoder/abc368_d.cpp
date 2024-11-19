#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

int total[N], remov[N];
bool need[N];
vector<int> v[N];

int recurs(int cur, int par)
{
	int i;
	total[cur] = 1;
	remov[cur] = 0;
	for (i=0; i<v[cur].size(); i++)
	{
		int nxt = v[cur][i];
		if (nxt != par)
		{
			remov[cur] += recurs(nxt, cur);
			total[cur] += total[nxt];
		}
	}
	if (!need[cur] && remov[cur] == total[cur] - 1)
	{
		++remov[cur];
	}
	return remov[cur];
}

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	int t;
	for (i=0; i<m; i++)
	{
		scanf("%d", &t);
		need[t] = true;
	}
	int ans = n - recurs(t, -1);
	printf("%d\n", ans);
	return 0;
}
