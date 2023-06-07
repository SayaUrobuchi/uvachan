#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
using pp = pair<int, int>;
 
const int N = 200005;
 
int tbl[N], lim[N];
vector<int> v[N];
 
int main()
{
	int n, m, i, j, p, q, t, mid, cnt;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		tbl[t]++;
	}
	for (i=1; i<=m; i++)
	{
		scanf("%d", &lim[i]);
	}
	priority_queue<pp, vector<pp>, greater<pp> > pq;
	for (i=m; i>0; )
	{
		if (!tbl[i])
		{
			--i;
			continue;
		}
		if (pq.empty() || pq.top().first >= lim[i])
		{
			t = pq.size();
		}
		else
		{
			t = pq.top().second;
			pq.pop();
		}
		v[t].emplace_back(i);
		--tbl[i];
		pq.emplace(v[t].size(), t);
	}
	printf("%d\n", (int)pq.size());
	for (i=0; i<(int)pq.size(); i++)
	{
		printf("%d", (int)v[i].size());
		for (j=0; j<v[i].size(); j++)
		{
			printf(" %d", v[i][j]);
		}
		puts("");
	}
	return 0;
}