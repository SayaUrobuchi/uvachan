#include <iostream>
#include <vector>
using namespace std;

const int M = 1000000007;

vector<int> v[262144];
int dis[262144], way[262144];
int qq[262144];

int main()
{
	int n, m, i, j, k, a, b, cur, nxt;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
			dis[i] = -1;
			way[i] = 0;
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			v[a].emplace_back(b);
			v[b].emplace_back(a);
		}
		qq[0] = 1;
		dis[1] = 0;
		way[1] = 1;
		for (i=0, j=1; i<j; i++)
		{
			cur = qq[i];
			if (cur == n)
			{
				break;
			}
			for (k=0; k<v[cur].size(); k++)
			{
				nxt = v[cur][k];
				if (dis[nxt] == -1)
				{
					dis[nxt] = dis[cur] + 1;
					qq[j] = nxt;
					j++;
				}
				if (dis[nxt] == dis[cur] + 1)
				{
					way[nxt] = (way[nxt] + way[cur]) % M;
				}
			}
		}
		printf("%d\n", way[n]);
	}
	return 0;
}
