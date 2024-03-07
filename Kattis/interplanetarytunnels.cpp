#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;

const int N = 10005;

bool used[N];
vector<int> v[N];

int main()
{
	int n, m, i, j, st, ed;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &st, &ed);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	vector<pp> que;
	que.emplace_back(st, 0);
	used[st] = true;
	int ans;
	for (i=0; i<que.size(); i++)
	{
		int cur, d;
		tie(cur, d) = que[i];
		if (cur == ed)
		{
			ans = d;
			break;
		}
		for (j=0; j<v[cur].size(); j++)
		{
			int nxt = v[cur][j];
			if (!used[nxt])
			{
				used[nxt] = true;
				que.emplace_back(nxt, d+1);
			}
		}
	}
	printf("%d\n", (ans+1) >> 1);
	return 0;
}
