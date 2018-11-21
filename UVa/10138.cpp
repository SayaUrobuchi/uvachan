#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, p, q, cmp;
int hcost[24];
int dis[1005];
int time[1005], hour[1005];
int type[1005];
int index[1005];
char buf[2008], buf2[2008];
char name[1005][25];

int comp(const void *l, const void *r)
{
	p = *(int*)l;
	q = *(int*)r;
	cmp = strcmp(name[p], name[q]);
	if(cmp)
	{
		return cmp;
	}
	return time[p] - time[q];
}

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int main()
{
	int count, i, m, d, h, min, cost, now, last;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0; i<24; i++)
		{
			scanf("%d", &hcost[i]);
		}
		gets(buf);
		n = 0;
		while(gets(buf))
		{
			if(!buf[0])
			{
				break;
			}
			sscanf(buf, "%s%d:%d:%d:%d%s%d", name[n], &m, &d, &h, &min, buf2, &dis[n]);
			time[n] = m*1000000 + d*10000 + h*100 + min;
			hour[n] = h;
			type[n] = buf2[4];
			index[n] = n;
			n++;
		}
		qsort(index, n, sizeof(int), comp);
		for(i=1, cost=-1; i<n; i++)
		{
			now = index[i];
			last = index[i-1];
			if(strcmp(name[now], name[last]))
			{
				if(cost != -1)
				{
					cost += 200;
					printf("%s $%d.%02d\n", name[last], cost/100, cost%100);
					cost = -1;
				}
			}
			else
			{
				if(type[last] && !type[now])
				{
					if(cost == -1)
					{
						cost = 0;
					}
					cost += ab(dis[now]-dis[last]) * hcost[hour[last]] + 100;
				}
			}
		}
		if(cost != -1)
		{
			cost += 200;
			printf("%s $%d.%02d\n", name[last], cost/100, cost%100);
			cost = -1;
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
