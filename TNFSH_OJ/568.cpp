#include<iostream>
#include <vector>
using namespace std;

const int N = 2048;

long long dis[N], cost[N][N];
vector<int> v[N], w[N];

int main() {
	int n, m, i, j, k, t, u, st, p, q, r;
	while (scanf("%d%d%d", &n, &m, &st) == 3)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
			w[i].clear();
			dis[i] = 1e18;
			for (j=0; j<=n; j++)
			{
				cost[i][j] = 1e18;
			}
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			v[p].push_back(q);
			w[p].push_back(r);
			v[q].push_back(p);
			w[q].push_back(r);
		}
		dis[st] = 0;
		cost[st][0] = 0;
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=n; j++)
			{
				for (k=0; k<v[j].size(); k++)
				{
					t = v[j][k];
					u = w[j][k];
					if (cost[t][i-1] + u < cost[j][i])
					{
						cost[j][i] = cost[t][i-1] + u;
						if (cost[j][i] * i < dis[j])
						{
							dis[j] = cost[j][i] * i;
						}
					}
				}
			}
		}
		printf("%lld", dis[1]);
		for (i=2; i<=n; i++)
		{
			printf(" %lld", dis[i]);
		}
		puts(" ");
	}
	return 0;
}

