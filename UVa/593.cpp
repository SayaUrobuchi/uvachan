#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INUM 12
#define HNUM 60
#define GNUM 25
#define LNUM 100005
#define STRLEN 25

int n, m, inum, hnum, acnum;
int gnum[GNUM];
int map[INUM][INUM];
int parent[HNUM];
int hname[HNUM];
int gname[GNUM];
int index[LNUM];
int listh[LNUM], listid[LNUM], listt[LNUM];
char iname[INUM][STRLEN];
char buf[1005];
int *ptr;
int *group[GNUM];

int comp(const void *p, const void *q)
{
	if(listh[*(int*)p] == listh[*(int*)q])
	{
		return listid[*(int*)p] - listid[*(int*)q];
	}
	return listh[*(int*)p] - listh[*(int*)q];
}

int getiindex(char *s)
{
	int i;
	for(i=1; i<inum; i++)
	{
		if(!strcmp(iname[i], s))
		{
			return i;
		}
	}
	strcpy(iname[i], s);
	return inum++;
}

int gethindex(int now)
{
	int i;
	for(i=1; i<hnum; i++)
	{
		if(hname[i] == now)
		{
			return i;
		}
	}
	hname[i] = now;
	return hnum++;
}

int getgindex(int now)
{
	int i;
	for(i=1; i<acnum; i++)
	{
		if(gname[i] == now)
		{
			return i;
		}
	}
	gname[i] = now;
	return acnum++;
}

int main()
{
	int cas, i, j, k, p, q, now, temp, id, ttl, target;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(map, 1, sizeof(map));
		hnum = inum = 1;
		for(i=1; i<=n; i++)
		{
			scanf("%s%d", buf, &m);
			now = getiindex(buf);
			map[now][now] = 0;
			while(m--)
			{
				scanf("%s", buf);
				if(buf[0] == 'T')
				{
					scanf("%d%s", &temp, buf);
					target = getiindex(buf);
					/*printf("%d => %d: %d\n", now, target, temp);*/
					map[now][target]/* = map[target][now]*/ = temp;
				}
				else
				{
					scanf("%d", &temp);
					parent[gethindex(temp)] = now;
				}
			}
		}
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
				{
					if(map[i][k] + map[k][j] < map[i][j])
					{
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
		/*for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				printf("%d => %d: %d\n", i, j, map[i][j]);
			}
		}*/
		acnum = 1;
		for(i=1; i<GNUM; i++)
		{
			group[i] = (int*)malloc(sizeof(int)*HNUM);
		}
		memset(gnum, 0, sizeof(gnum));
		k = 0;
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s", buf);
			if(buf[0] == 'J')
			{
				scanf("%d%d", &p, &q);
				p = gethindex(p);
				now = getgindex(q);
				group[now][gnum[now]++] = p;
			}
			else if(buf[0] == 'L')
			{
				scanf("%d%d", &p, &q);
				p = gethindex(p);
				now = getgindex(q);
				for(i=0; i<gnum[now]; i++)
				{
					if(group[now][i] == p)
					{
						break;
					}
				}
				group[now][i] = group[now][--gnum[now]];
				if(!gnum[now])
				{
					gnum[now] = gnum[--acnum];
					ptr = group[now];
					group[now] = group[acnum];
					group[acnum] = ptr;
				}
			}
			else
			{
				scanf("%d%d%d%d", &temp, &now, &id, &ttl);
				temp = parent[gethindex(temp)];
				now = getgindex(now);
				for(i=0; i<gnum[now]; i++)
				{
					p = group[now][i];
					/*printf("%d\n", p);*/
					/*printf("%d %d: %d compare %d\n", parent[p], temp, map[temp][parent[p]], ttl);*/
					if(map[temp][parent[p]] <= ttl)
					{
						index[k] = k;
						listh[k] = hname[p];
						listid[k] = id;
						listt[k] = ttl - map[temp][parent[p]];
						k++;
					}
				}
			}
		}
		qsort(index, k, sizeof(int), comp);
		printf("Network #%d\n", ++cas);
		for(i=0; i<k; i++)
		{
			printf("%d %d %d\n", listh[index[i]], listid[index[i]], listt[index[i]]);
		}
		printf("\n");
	}
	return 0;
}
