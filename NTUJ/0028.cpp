#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int root, m, parent[25], num[25], map[25][25], used[25], dis[25], dd[25][25], list[25];
char name[25][20], s1[20], s2[20];

typedef struct edge
{
	int p, q, l;
}edge;

edge eg[10005];

int comp(const void *p, const void *q)
{
	return ((edge*)p)->l - ((edge*)q)->l;
}

int max(int p, int q)
{
	return p>q ? p : q;
}

int getparent(int now)
{
	if(parent[now] != -1)
	{
		return parent[now]=getparent(parent[now]);
	}
	return now;
}

int search(char *s)
{
	int i;
	for(i=0; i<m; i++)
	{
		if(strcmp(s, name[i]) == 0)
		{
			return i;
		}
	}
	strcpy(name[m++], s);
	return i;
}

void getdis(int now, int maxdis)
{
	int i;
	used[now] = 1;
	dis[now] = maxdis;
	for(i=0; i<num[now]; i++)
	{
		if(used[map[now][i]] == 0)
		{
			getdis(map[now][i], now==root?-1:max(maxdis, dd[now][map[now][i]]));
		}
	}
}

void del(int now, int tar, int dep)
{
	int i, j, p, q, temp;
	list[dep] = now;
	used[now] = 1;
	if(now == tar)
	{
		for(i=dep, j=-1; i>1; i--)
		{
			if(dd[list[i]][list[i-1]] > j)
			{
				j = dd[list[i]][list[i-1]];
				temp = i;
			}
		}
		p = list[temp];
		q = list[temp-1];
		for(i=0; i<num[p]; i++)
		{
			if(map[p][i] == q)
			{
				map[p][i] = map[p][--num[p]];
				break;
			}
		}
		for(i=0; i<num[q]; i++)
		{
			if(map[q][i] == p)
			{
				map[q][i] = map[q][--num[q]];
				break;
			}
		}
		return;
	}
	for(i=0; i<num[now]; i++)
	{
		if(used[map[now][i]] == 0)
		{
			del(map[now][i], tar, dep+1);
		}
	}
}

int main()
{
	int n, i, j, p, q, d, c, cc, maxn, cost, temp;
	while(scanf("%d", &n) == 1)
	{
		memset(dd, 127, sizeof(dd));
		memset(num, 0, sizeof(num));
		for(i=0, m=0; i<n; i++)
		{
			scanf("%s%s%d", s1, s2, &eg[i].l);
			eg[i].p = search(s1);
			eg[i].q = search(s2);
			dd[eg[i].p][eg[i].q] = dd[eg[i].q][eg[i].p] = eg[i].l;
		}
		qsort(eg, n, sizeof(edge), comp);
		memset(parent, -1, sizeof(parent));
		root = search("Park");
		for(i=0, cost=0, c=0; i<n; i++)
		{
			if(eg[i].p == root || eg[i].q == root)
			{
				continue;
			}
			p = getparent(eg[i].p);
			q = getparent(eg[i].q);
			if(p != q)
			{
				c++;
				parent[p] = q;
				cost += eg[i].l;
				p = eg[i].p;
				q = eg[i].q;
				map[p][num[p]++] = q;
				map[q][num[q]++] = p;
			}
		}
		scanf("%d", &d);
		for(i=0, cc=0; i<n; i++)
		{
			p = getparent(eg[i].p);
			q = getparent(eg[i].q);
			if(p != q)
			{
				c++;
				cc++;
				parent[p] = q;
				cost += eg[i].l;
				p = eg[i].p;
				q = eg[i].q;
				map[p][num[p]++] = q;
				map[q][num[q]++] = p;
			}
		}
		for(; cc<d; cc++)
		{
			memset(used, 0, sizeof(used));
			getdis(root, -1);
			for(j=0, maxn=0; j<m; j++)
			{
				if(j != root && dd[root][j] - dis[j] < maxn)
				{
					maxn = dd[root][j] - dis[j];
					temp = j;
				}
			}
			if(maxn == 0)
			{
				break;
			}
			cost += maxn;
			memset(used, 0, sizeof(used));
			del(root, temp, 0);
			map[root][num[root]++] = temp;
			map[temp][num[temp]++] = root;
		}
		printf("Total miles driven: %d\n", cost);
	}
	return 0;
}
