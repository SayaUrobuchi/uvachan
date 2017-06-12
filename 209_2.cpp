#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 270

int dist;
int dp[N];
int v[8];
int used[8];
int px[8], py[8];
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

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

void getcoor(int i)
{
	px[i] = bisearch(1, N-1, v[i]) - 1;
	py[i] = v[i]-dp[px[i]]-1;
}

void print(int s)
{
	int i;
	for(i=0; i<s; i++)
	{
		printf("%d ", v[i]);
	}
}

int getdis(int p, int q)
{
	if(px[p] == px[q])
	{
		return ab(py[p]-py[q]);
	}
	return ab(px[p]-px[q]);
}

int conn(int p, int q)
{
	return px[p] == px[q] || py[p] == py[q] || ab(px[p]-px[q]) == ab(py[p]-py[q]);
}

int dfs(int now, int depth, int limit)
{
	int i;
	if(depth == limit)
	{
		return getdis(now, 0) == dist;
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
				if(getdis(now, i) == dist)
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
			if(conn(0, 1) && conn(0, 2) && conn(1, 2))
			{
				/*printf("%d %d %d\n", getdis(0, 1), getdis(0, 2), getdis(1, 2));*/
				if(getdis(0, 1) == getdis(0, 2) && getdis(0, 1) == getdis(1, 2))
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
