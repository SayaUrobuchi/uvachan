#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
using pp = pair<int, int>;

const int N = 200005;

int ary[N];
bool used[N];
vector<int> v[N];

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
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	priority_queue<pp, vector<pp>, greater<pp> > pq;
	pq.emplace(0, 1);
	used[1] = true;
	int army = ary[1];
	while (!pq.empty())
	{
		int siz, cur;
		tie(siz, cur) = pq.top();
		pq.pop();
		if (siz >= army)
		{
			break;
		}
		army += siz;
		for (i=0; i<v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			if (!used[nxt])
			{
				used[nxt] = true;
				pq.emplace(ary[nxt], nxt);
			}
		}
	}
	printf("%d\n", army);
	return 0;
}
