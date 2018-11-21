#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DPN 1050
#define QN 3000000

int n, m, num;
int px[DPN], py[DPN], cost[505];
int xlist[DPN], ylist[DPN], inq[DPN];
long long dis[DPN];
int qq[QN];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

long long ab(long long t)
{
	return t<0 ? -t : t;
}

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
	int i, j, k, x, y, sx, sy, ex, ey, nx, ny, sn, en, nn, pid, lim;
	long long d;
	while(scanf("%d%d", &n, &m) == 2)
	{
		scanf("%d", &num);
		for(i=0; i<num; i++)
		{
			scanf("%d%d%d%d%d", &px[i], &py[i], &px[i+num+2], &py[i+num+2], &cost[i]);
		}
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		px[num] = px[num+num+2] = sx;
		py[num] = py[num+num+2] = sy;
		px[num+1] = px[num+1+num+2] = ex;
		py[num+1] = py[num+1+num+2] = ey;
		sn = num++;
		en = num++;
		memset(inq, 0, sizeof(inq));
		memset(dis, -1, sizeof(dis));
		inq[sn] = 1;
		qq[0] = sn;
		dis[sn] = 0;
		for(i=0, j=1; i<j; i++)
		{
			nn = qq[i];
			x = px[nn];
			y = py[nn];
			inq[nn] = 0;
			pid = nn >= num ? nn-num : nn+num;
			d = dis[nn] + cost[nn>=num?nn-num:nn];
			nx = px[pid];
			ny = py[pid];
			if(dis[pid] == -1 || dis[pid] > d)
			{
				dis[pid] = d;
				if(!inq[pid])
				{
					inq[pid] = 1;
					qq[j] = pid;
					j++;
				}
			}
			for(k=0, lim=(num<<1); k<lim; k++)
			{
				nx = px[k];
				ny = py[k];
				d = dis[nn] + ab(nx-x) + ab(ny-y);
				if(dis[k] == -1 || dis[k] > d)
				{
					dis[k] = d;
					if(!inq[k])
					{
						inq[k] = 1;
						qq[j] = k;
						j++;
					}
				}
			}
		}
		printf("%I64d\n", dis[en]);
	}
	return 0;
}
