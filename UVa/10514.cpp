#include <stdio.h>
#include <math.h>

#define INF 1e25

int num[25];
double map[25][25];

struct vector
{
	int x, y;
};

struct point
{
	int x, y;
};

struct point vertice[25][105];

double min(double p, double q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int dot(struct vector p, struct vector q)
{
	return p.x * q.x + p.y * q.y;
}

int cross(struct vector p, struct vector q)
{
	return p.x * q.y - p.y * q.x;
}

double dist(struct point p, struct point q)
{
	int x, y;
	x = p.x - q.x;
	y = p.y - q.y;
	return sqrt((double)x*x+y*y);
}

double length(struct vector v)
{
	return sqrt((double)v.x*v.x+v.y*v.y);
}

double ptos(struct point p, struct point p1, struct point p2)
{
	struct vector v1, v2, v3, v4;
	v1.x = p.x - p1.x;
	v1.y = p.y - p1.y;
	v2.x = p2.x - p1.x;
	v2.y = p2.y - p1.y;
	v3.x = p.x - p2.x;
	v3.y = p.y - p2.y;
	v4.x = p1.x - p2.x;
	v4.y = p1.y - p2.y;
	if(dot(v1, v2) > 0 && dot(v3, v4) > 0)
	{
		return ab(cross(v1, v2)) / length(v2);
	}
	return min(dist(p, p1), dist(p, p2));
}

double getsegdist(struct point p1, struct point p2, struct point p3, struct point p4)
{
	return min(ptos(p1, p3, p4), min(ptos(p2, p3, p4), min(ptos(p3, p1, p2), ptos(p4, p1, p2))));
}

double getdist(int p, int q)
{
	int i, j;
	double ans;
	ans = INF;
	for(i=1; i<num[p]; i++)
	{
		for(j=1; j<num[q]; j++)
		{
			ans = min(ans, getsegdist(vertice[p][i-1], vertice[p][i], vertice[q][j-1], vertice[q][j]));
		}
	}
	return ans;
}

int main()
{
	int count, n, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &num[0], &num[1], &n);
		for(i=0; i<num[0]; i++)
		{
			scanf("%d%d", &vertice[0][i].x, &vertice[0][i].y);
			map[0][0] = 0.0;
		}
		for(i=0; i<num[1]; i++)
		{
			scanf("%d%d", &vertice[1][i].x, &vertice[1][i].y);
			map[1][0] = map[0][1] = getdist(0, 1);
			map[1][1] = 0.0;
		}
		for(i=2, n+=2; i<n; i++)
		{
			scanf("%d", &num[i]);
			for(j=0; j<num[i]; j++)
			{
				scanf("%d%d", &vertice[i][j].x, &vertice[i][j].y);
			}
			vertice[i][j].x = vertice[i][0].x;
			vertice[i][j].y = vertice[i][0].y;
			num[i]++;
			for(j=0; j<i; j++)
			{
				map[i][j] = map[j][i] = getdist(i, j);
			}
			map[i][i] = 0.0;
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					if(map[i][j] > map[i][k] + map[k][j])
					{
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
		printf("%.3lf\n", map[0][1]);
	}
	return 0;
}
