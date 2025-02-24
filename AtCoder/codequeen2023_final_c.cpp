#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

int s, t;
int dis[N];
bool flag[N];
vector<int> edg[N];

bool travel(int cur, int par)
{
	if (cur == t)
	{
		return flag[cur] = true;
	}
	int i;
	for (i=0; i<edg[cur].size()&&!flag[cur]; i++)
	{
		int nxt = edg[cur][i];
		if (nxt != par)
		{
			flag[cur] |= travel(nxt, cur);
		}
	}
	return flag[cur];
}

void find_dis(int cur, int par, int d)
{
	dis[cur] = d + 1;
	int i;
	for (i=0; i<edg[cur].size(); i++)
	{
		int nxt = edg[cur][i];
		if (nxt != par)
		{
			find_dis(nxt, cur, d+1-flag[nxt]);
		}
	}
}

int main()
{
	int n, i;
	scanf("%d%d%d", &n, &s, &t);
	for (i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edg[a].emplace_back(b);
		edg[b].emplace_back(a);
	}
	travel(s, -1);
	find_dis(s, -1, 0);
	for (i=1; i<=n; i++)
	{
		printf("%d\n", dis[i]);
	}
	return 0;
}