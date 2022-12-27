#include <iostream>
#include <vector>
using namespace std;

const int NONE = 0;
const int EITHER = 1;
const int BOTH = 2;
const int N = 200005;

bool gg;
int ucnt, total, cnt;
int used[N];
vector<int> edg[N];
bool det[N], val[N];

void dfs(int cur)
{
	int i, nxt;
	det[cur] = true;
	used[cur] = ucnt;
	++total;
	cnt += val[cur];
	for (i=0; i<edg[cur].size()&&!gg; i++)
	{
		nxt = edg[cur][i];
		if (det[nxt] || used[nxt] == ucnt)
		{
			if (val[nxt] == val[cur])
			{
				gg = true;
			}
		}
		else
		{
			val[nxt] = !val[cur];
			dfs(nxt);
		}
	}
}

int main()
{
	int n, m, i, a, b, c, t, ans;
	scanf("%d%d", &n, &m);
	gg = false;
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (c == NONE)
		{
			t = 0;
		}
		else if (c == BOTH)
		{
			t = 1;
		}
		
		if (c == EITHER)
		{
			edg[a].emplace_back(b);
			edg[b].emplace_back(a);
		}
		else
		{
			if (det[a] && val[a] != t)
			{
				gg = true;
			}
			if (det[b] && val[b] != t)
			{
				gg = true;
			}
			det[a] = true;
			val[a] = t;
			det[b] = true;
			val[b] = t;
		}
	}
	if (!gg)
	{
		++ucnt;
		for (i=1, ans=0; i<=n&&!gg; i++)
		{
			if (det[i] && used[i] != ucnt)
			{
				dfs(i);
			}
		}
		for (i=1, ans=0; i<=n&&!gg; i++)
		{
			if (det[i])
			{
				ans += val[i];
			}
		}
		++ucnt;
		for (i=1; i<=n&&!gg; i++)
		{
			if (!det[i])
			{
				cnt = 0;
				total = 0;
				val[i] = 0;
				dfs(i);
				ans += min(cnt, total-cnt);
			}
		}
	}
	if (gg)
	{
		puts("impossible");
	}
	else
	{
		printf("%d\n", ans);
	}
	return 0;
}