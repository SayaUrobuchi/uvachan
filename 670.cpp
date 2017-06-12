#include <stdio.h>
#include <string.h>
#include <math.h>

int px[101], py[101];
int ix[101], iy[101];
int visit[101];
int target[101];
int pused[101], iused[101];
int map[101][101];
int pptr[101], pnum[101];
double dist[101];

int fill(int);

double ab(double now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int equal(double now)
{
	return ab(now) < 1e-5;
}

double dis(int x, int y)
{
	return sqrt(x*x + y*y);
}

int dovisit(int now)
{
	if(!visit[now])
	{
		return 1;
	}
	if(!pused[visit[now]-1])
	{
		return fill(visit[now]-1);
	}
	return 0;
}

int fill(int now)
{
	int i, temp;
	pused[now] = 1;
	for(; pptr[now]<pnum[now]; pptr[now]++)
	{
		if(!visit[temp=map[now][pptr[now]]])
		{
			target[now] = temp + 1;
			visit[temp] = now + 1;
			return 1;
		}
	}
	for(i=0; i<pnum[now]; i++)
	{
		if(!iused[map[now][i]])
		{
			iused[map[now][i]] = 1;
			if(dovisit(temp=map[now][i]))
			{
				target[now] = temp + 1;
				visit[temp] = now + 1;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int count, n, m, i, j, c;
	double temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			pptr[i] = 0;
			if(i)
			{
				dist[i] = dis(px[i]-px[i-1], py[i]-py[i-1]);
			}
		}
		memset(pnum, 0, sizeof(pnum));
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &ix[i], &iy[i]);
			for(j=1; j<n; j++)
			{
				temp = dis(ix[i]-px[j-1], iy[i]-py[j-1]) + dis(px[j]-ix[i], py[j]-iy[i]);
				if(dist[j] + dist[j] > temp || equal(dist[j]+dist[j]-temp))
				{
					map[j][pnum[j]++] = i;
				}
			}
		}
		memset(visit, 0, sizeof(visit));
		for(i=1, c=0; i<n; i++)
		{
			target[i] = 0;
			memset(pused, 0, sizeof(pused));
			memset(iused, 0, sizeof(iused));
			c += fill(i);
		}
		printf("%d\n%d %d", n+c, px[0], py[0]);
		for(i=1; i<n; i++)
		{
			if(target[i])
			{
				printf(" %d %d", ix[target[i]-1], iy[target[i]-1]);
			}
			printf(" %d %d", px[i], py[i]);
		}
		printf("\n");
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
