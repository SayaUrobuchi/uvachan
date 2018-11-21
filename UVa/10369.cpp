#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define INF 2147483647

int qnum;
int px[505], py[505];
int queue[505], qx[505], qy[505];
int dis[505], used[505], from[505];

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int getdis(int x, int y)
{
	return x*x + y*y;
}

int main()
{
	int count, n, m, i, j, d, max, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		for(i=1, qnum=0; i<n; i++)
		{
			dis[i] = getdis(px[0]-px[i], py[0]-py[i]);
			from[i] = 0;
		}
		memset(used, 0, sizeof(used));
		used[0] = 1;
		for(j=1; j<n; j++)
		{
			for(i=1, max=INF; i<n; i++)
			{
				if(!used[i] && dis[i] < max)
				{
					max = dis[i];
					temp = i;
				}
			}
			used[temp] = 1;
			qx[qnum] = temp;
			qy[qnum] = from[temp];
			queue[qnum++] = max;
			for(i=1; i<n; i++)
			{
				if(!used[i] && (d=getdis(px[i]-px[temp], py[i]-py[temp])) < dis[i])
				{
					dis[i] = d;
					from[i] = temp;
				}
			}
		}
		qsort(queue, qnum, sizeof(int), comp);
		for(i=0; i<qnum&&m; i++)
		{
			d = used[qx[i]] + used[qy[i]];
			if(d <= m)
			{
				m -= d;
				used[qx[i]] = used[qy[i]] = 0;
			}
			else
			{
				break;
			}
		}
		if(i < qnum)
		{
			printf("%.2lf\n", sqrt(queue[i]));
		}
		else
		{
			printf("0.00\n");
		}
	}
	return 0;
}
