#include <iostream>
#include <queue>
using namespace std;
using pp = pair<int, int>;
using pppq = priority_queue<pp, vector<pp>, greater<pp> >;

int dis[1024], mat[1024][1024];

int main()
{
	int n, st, ed, i, j;
	while (scanf("%d%d%d", &n, &st, &ed) == 3)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &mat[i][j]);
			}
			dis[i] = 2147483647;
		}
		pppq pq;
		dis[st] = 0;
		pq.emplace(0, st);
		while (pq.size())
		{
			pp now = pq.top();
			pq.pop();
			if (now.first != dis[now.second])
			{
				continue;
			}
			if (now.second == ed)
			{
				break;
			}
			for (i=0; i<n; i++)
			{
				if (dis[i] > dis[now.second] + mat[now.second][i])
				{
					dis[i] = dis[now.second] + mat[now.second][i];
					pq.emplace(dis[i], i);
				}
			}
		}
		printf("%d\n", dis[ed]);
	}
	return 0;
}
