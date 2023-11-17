#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;
using data_t = pair<int, pp>;

const int N = 100005;

vector<int> edg[N], path;
bool used[N];

void backtrack(int cur, const vector<data_t> &que)
{
	int nxt = que[cur].second.second;
	if (nxt > 0)
	{
		backtrack(nxt, que);
	}
	path.emplace_back(que[cur].first);
}

int bfs(int st, int ed)
{
	int i, j, ans;
	vector<data_t> que;
	used[st] = true;
	que.emplace_back(st, make_pair(1, -1));
	for (i=0, ans=-1; i<que.size(); i++)
	{
		int cur, d, f;
		forward_as_tuple(cur, tie(d, f)) = que[i];
		if (cur == ed)
		{
			ans = i;
			break;
		}
		for (j=0; j<edg[cur].size(); j++)
		{
			int nxt = edg[cur][j];
			if (!used[nxt])
			{
				used[nxt] = true;
				que.emplace_back(nxt, make_pair(d+1, i));
			}
		}
	}
	if (ans >= 0)
	{
		backtrack(ans, que);
		return que[ans].second.first;
	}
	return ans;
}

int main()
{
	int n, m, i, a, b;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		edg[a].emplace_back(b);
		edg[b].emplace_back(a);
	}
	int ans = bfs(1, n);
	if (ans > 0)
	{
		printf("%d\n", ans);
		printf("1");
		for (i=0; i<path.size(); i++)
		{
			printf(" %d", path[i]);
		}
		puts("");
	}
	else
	{
		puts("IMPOSSIBLE");
	}
	return 0;
}
