#include <stdio.h>
#include <string.h>
#include <math.h>

#define Infinity 1e15

int n, m, o;
int holed[60];
int lived[110];
int from[110];
int used[110];
double dist[110];
double x[110], y[110];
double map[110][110];
double label[110];

double max(double p, double q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

double getdist(double xcoor, double ycoor)
{
	return sqrt(xcoor * xcoor + ycoor * ycoor);
}

double trans(int u, int v, double cost)
{
	return max(0.0, label[u] - label[v] + cost);
}

int main()
{
	int cas, count, i, j, lim, temp;
	double mincost;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &x[i], &y[i]);
		}
		for(i=0; i<m; i++)
		{
			scanf("%lf%lf", &x[i+n], &y[i+n]);
			for(j=0; j<n; j++)
			{
				map[j][i+n] = getdist(x[j]-x[i+n], y[j]-y[i+n]);
			}
		}
		memset(label, 0, sizeof(label));
		memset(holed, 0, sizeof(holed));
		memset(lived, 0, sizeof(lived));
		for(i=0, lim=n+m; i<n-o; i++)
		{
			for(j=0; j<n; j++)
			{
				if(holed[j])
				{
					dist[j] = Infinity;
				}
				else
				{
					dist[j] = 0.0;
					from[j] = -1;
				}
				used[j] = 0;
			}
			for(; j<=lim; j++)
			{
				dist[j] = Infinity;
				used[j] = 0;
			}
			for(; ; )
			{
				for(j=0, mincost=Infinity; j<=lim; j++)
				{
					if(!used[j] && dist[j] < mincost)
					{
						mincost = dist[j];
						temp = j;
					}
				}
				if(mincost == Infinity)
				{
					break;
				}
				used[temp] = 1;
				if(temp < n)
				{
					for(j=n; j<lim; j++)
					{
						if(!used[j] && trans(temp, j, map[temp][j]) < dist[j])
						{
							dist[j] = trans(temp, j, map[temp][j]);
							/*printf("%d->%d, %.3lf\n", temp, j, dist[j]);*/
							from[j] = temp;
						}
					}
				}
				else if(temp < lim)
				{
					if(lived[temp])
					{
						j = lived[temp] - 1;
						if(!used[j] && trans(temp, j, -map[j][temp]) < dist[j])
						{
							dist[j] = trans(temp, j, -map[j][temp]);
							/*printf("%d->%d, %.3lf\n", temp, j, dist[j]);*/
							from[j] = temp;
						}
					}
					else if(!used[lim] && trans(temp, lim, 0.0) < dist[lim])
					{
						dist[lim] = trans(temp, lim, 0.0);
						/*printf("%.3lf\n", dist[lim]);*/
						from[lim] = temp;
					}
				}
			}
			if(!used[lim])
			{
				break;
			}
			for(j=from[lim]; ; )
			{
				lived[j] = from[j] + 1;
				holed[from[j]] = j;
				j = from[j];
				if(from[j] == -1)
				{
					break;
				}
				j = from[j];
			}
			for(j=0; j<=lim; j++)
			{
				if(label[j] < Infinity)
				{
					label[j] += dist[j];
				}
			}
			for(j=0, mincost=0; j<n; j++)
			{
				if(holed[j])
				{
					/*printf("%d -> %d, dist: %.3lf\n", i, holed[i], map[i][holed[i]]);*/
					if(map[j][holed[j]] > mincost)
					{
						mincost = map[j][holed[j]];
					}
				}
			}
			printf("Case #%d:\n%.3lf\n\n", cas, mincost);
		}
		if(i == n-o)
		{
			for(i=0, mincost=0; i<n; i++)
			{
				if(holed[i])
				{
					/*printf("%d -> %d, dist: %.3lf\n", i, holed[i], map[i][holed[i]]);*/
					if(map[i][holed[i]] > mincost)
					{
						mincost = map[i][holed[i]];
					}
				}
			}
			printf("Case #%d:\n%.3lf\n\n", ++cas, mincost);
		}
		else
		{
			printf("Case #%d:\nToo bad.\n\n", ++cas);
		}
	}
	return 0;
}
