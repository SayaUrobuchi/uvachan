#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parent[101];
int start[100001], end[100001];
int cost[100001];
int index[100001];
int ary[100001];

int comp(const void *p, const void *q)
{
	return cost[*(int*)p] - cost[*(int*)q];
}

int getparent(int now)
{
	if(parent[now])
	{
		return parent[now]=getparent(parent[now]);
	}
	return now;
}

int main()
{
	int count, n, m, i, j, k, c, chk, temp, mincost, seccost;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &start[i], &end[i], &cost[i]);
			index[i] = i;
		}
		qsort(index, m, sizeof(int), comp);
		memset(parent, 0, sizeof(parent));
		for(i=0, mincost=0, k=0; i<m; i++)
		{
			temp = index[i];
			if(getparent(start[temp]) != getparent(end[temp]))
			{
				parent[getparent(start[temp])] = getparent(end[temp]);
				mincost += cost[temp];
				ary[k++] = i;
			}
		}
		for(i=0, seccost=2147483640; i<k; i++)
		{
			memset(parent, 0, sizeof(parent));
			for(j=0, c=0, chk=1; j<m; j++)
			{
				if(j != ary[i])
				{
					temp = index[j];
					if(getparent(start[temp]) != getparent(end[temp]))
					{
						parent[getparent(start[temp])] = getparent(end[temp]);
						c += cost[temp];
						chk++;
					}
				}
			}
			if(chk == n)
			{
				if(c < seccost)
				{
					seccost = c;
				}
			}
		}
		printf("%d %d\n", mincost, seccost);
	}
	return 0;
}
