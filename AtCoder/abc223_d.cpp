#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, m, i, a, b;
	scanf("%d%d", &n, &m);
	vector<vector<int> > v(n+1);
	vector<int> deg(n+1);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		++deg[b];
	}
	priority_queue<int, vector<int>, greater<int> > pq;
	for (i=1; i<=n; i++)
	{
		if (deg[i] == 0)
		{
			pq.emplace(i);
		}
	}
	vector<int> ansa;
	while (!pq.empty())
	{
		int cur = pq.top();
		ansa.emplace_back(cur);
		pq.pop();
		for (i=0; i<v[cur].size(); i++)
		{
			int nxt = v[cur][i];
			--deg[nxt];
			if (deg[nxt] == 0)
			{
				pq.emplace(nxt);
			}
		}
	}
	if (ansa.size() != n)
	{
		puts("-1");
	}
	else
	{
		printf("%d", ansa[0]);
		for (i=1; i<n; i++)
		{
			printf(" %d", ansa[i]);
		}
		puts("");
	}
	return 0;
}
