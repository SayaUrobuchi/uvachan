#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;

int bk[N];
bool used[N];
vector<int> edg[N];

int main()
{
	int n, m, i, k;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edg[a].emplace_back(b);
		edg[b].emplace_back(a);
	}
	vector<int> que;
	used[1] = true;
	que.emplace_back(1);
	for (i=0; i<que.size(); i++)
	{
		int cur = que[i];
		for (k=0; k<edg[cur].size(); k++)
		{
			int nxt = edg[cur][k];
			if (!used[nxt])
			{
				used[nxt] = true;
				bk[nxt] = cur;
				que.emplace_back(nxt);
			}
		}
	}
	puts("Yes");
	for (i=2; i<=n; i++)
	{
		printf("%d\n", bk[i]);
	}
	return 0;
}
