#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 270

int dp[N];
int v[8];
int used[8];
int deg[8], count[8];
double px[8], py[8];
double sq3, dist;
char buf[2008];

int bisearch(int left, int right, int target)
{
	int center;
	if(left > right)
	{
		return left;
	}
	center = left + right;
	center /= 2;
	if(dp[center] >= target)
	{
		return bisearch(left, center-1, target);
	}
	return bisearch(center+1, right, target);
}

double ab(double now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

void getcoor(int i)
{
	px[i] = (deg[i] = bisearch(1, N-1, v[i]) - 1) * sq3;
	py[i] = -deg[i] + ((v[i] - dp[deg[i]] - 1) * 2.0);
	count[i] = -deg[i] + ((v[i]-dp[deg[i]]-1)<<1);
}

void print(int s)
{
	int i;
	for(i=0; i<s; i++)
	{
		printf("%d ", v[i]);
	}
}

double getdis(int p, int q)
{
	double x, y;
	x = px[p] - px[q];
	y = py[p] - py[q];
	return x*x + y*y;
}

int conn(int p, int q)
{
	return deg[p] == deg[q] || count[p] == count[q] || ab(deg[p]-deg[q]) == ab(count[p]-count[q]);
}

int equal(double now)
{
	return ab(now) < 1e-8;
}

int dfs(int now, int depth, int limit)
{
	int i;
	if(depth == limit)
	{
		return equal(getdis(now, 0)-dist);
	}
	for(i=1; i<limit; i++)
	{
		if(!used[i] && conn(now, i))
		{
			used[i] = 1;
			if(!now)
			{
				dist = getdis(0, i);
				if(dfs(i, depth+1, limit))
				{
					return 1;
				}
			}
			else
			{
				if(equal(getdis(now, i)-dist))
				{
					if(dfs(i, depth+1, limit))
					{
						return 1;
					}
				}
			}
			used[i] = 0;
		}
	}
	return 0;
}

int main()
{
	int i, s;
	sq3 = sqrt(3.0);
	dp[1] = 1;
	for(i=2; i<N; i++)
	{
		dp[i] = dp[i-1] + i;
	}
	while(gets(buf))
	{
		s = sscanf(buf, "%d%d%d%d%d%d", &v[0], &v[1], &v[2], &v[3], &v[4], &v[5]);
		for(i=0; i<s; i++)
		{
			getcoor(i);
		}
		print(s);
		if(s == 3)
		{
			/*printf("%d %d %d\n", conn(0, 1), conn(0, 2), conn(1, 2));*/
			if(conn(0, 1) && conn(0, 2) && conn(1, 2))
			{
				if(equal(getdis(0, 1)-getdis(0, 2)) && equal(getdis(0, 1)-getdis(1, 2)))
				{
					printf("are the vertices of a triangle\n");
				}
				else
				{
					printf("are not the vertices of an acceptable figure\n");
				}
			}
			else
			{
				printf("are not the vertices of an acceptable figure\n");
			}
		}
		else if(s == 4)
		{
			memset(used, 0, sizeof(used));
			if(dfs(0, 1, s))
			{
				printf("are the vertices of a parallelogram\n");
			}
			else
			{
				printf("are not the vertices of an acceptable figure\n");
			}
		}
		else if(s == 6)
		{
			memset(used, 0, sizeof(used));
			if(dfs(0, 1, s))
			{
				printf("are the vertices of a hexagon\n");
			}
			else
			{
				printf("are not the vertices of an acceptable figure\n");
			}
		}
		else
		{
			printf("are not the vertices of an acceptable figure\n");
		}
	}
	return 0;
}
