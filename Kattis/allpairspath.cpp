#include <iostream>
using namespace std;

const int N = 160;

long long dis[N][N];
bool conn[N][N];

int main()
{
	int n, m, o, i, j, k, a, b, c;
	bool neg_cir;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if (!n && !m && !o)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				dis[i][j] = 0;
				conn[i][j] = (i == j);
			}
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (!conn[a][b] || dis[a][b] > c)
			{
				dis[a][b] = c;
				conn[a][b] = true;
			}
		}
		for (k=0; k<n; k++)
		{
			for (i=0; i<n; i++)
			{
				if (conn[i][k])
				{
					for (j=0; j<n; j++)
					{
						if (conn[k][j])
						{
							if (!conn[i][j] || dis[i][j] > dis[i][k] + dis[k][j])
							{
								conn[i][j] = true;
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
			if (!conn[a][b])
			{
				puts("Impossible");
			}
			else
			{
				neg_cir = false;
				for (k=0; k<n&&!neg_cir; k++)
				{
					if (conn[a][k] && conn[k][b] && dis[k][k] < 0)
					{
						neg_cir = true;
					}
				}
				if (neg_cir)
				{
					puts("-Infinity");
				}
				else
				{
					printf("%lld\n", dis[a][b]);
				}
			}
		}
		puts("");
	}
	return 0;
}