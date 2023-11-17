#include <iostream>
using namespace std;

const int N = 512;

long long dis[N][N];

int main()
{
	int n, m, o, i, j, k, a, b, c;
	scanf("%d%d%d", &n, &m, &o);
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
		{
			if (i == j)
			{
				dis[i][j] = 0;
			}
			else
			{
				dis[i][j] = -1;
			}
		}
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (dis[a][b] < 0 || dis[a][b] > c)
		{
			dis[a][b] = dis[b][a] = c;
		}
	}
	for (k=1; k<=n; k++)
	{
		for (i=1; i<=n; i++)
		{
			if (dis[i][k] >= 0)
			{
				for (j=1; j<=n; j++)
				{
					if (dis[k][j] >= 0)
					{
						if (dis[i][j] < 0 || dis[i][j] > dis[i][k] + dis[k][j])
						{
							dis[i][j] = dis[i][k] + dis[k][j];
						}
					}
				}
			}
		}
	}
	for (i=0; i<o; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%lld\n", dis[a][b]);
	}
	return 0;
}
