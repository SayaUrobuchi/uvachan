#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using pp = pair<int, pair<int, int> >;

int board[3005][3005], dis[3005];

int main()
{
	int n, i, j, cur;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=n; j++)
			{
				scanf("%d", &board[i][j]);
			}
		}
		priority_queue<pp, vector<pp>, greater<pp> > pq;
		for (i=2; i<=n; i++)
		{
			dis[i] = board[1][i];
			pq.push({dis[i], {1, i}});
		}
		while (!pq.empty())
		{
			pp nod = pq.top();
			pq.pop();
			cur = nod.second.second;
			if (dis[cur] != nod.first)
			{
				continue;
			}
			dis[cur] = -1;
			printf("%d %d\n", nod.second.first, cur);
			for (i=2; i<=n; i++)
			{
				if (i != cur && board[cur][i] < dis[i])
				{
					dis[i] = board[cur][i];
					pq.push({dis[i], {cur, i}});
				}
			}
		}
	}
	return 0;
}
