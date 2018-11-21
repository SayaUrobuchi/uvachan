#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ecnt, pcnt;
int ex[100005], ey[100005], es[100005], pp[100005], used[100005], ind[100005];
int list[100005], poi[100005], res[100005], root[100005];

int e_comp(const void *p, const void *q)
{
	return ex[*(int*)p] - ex[*(int*)q];
}

int re_comp(const void *p, const void *q)
{
	return ey[*(int*)p] - ey[*(int*)q];
}

void dfs(int t)
{
	int i;
	used[t] = 1;
	for(i=es[t]; i>=0; i--)
	{
		if(ex[pp[i]] != t)
		{
			break;
		}
		if(used[ey[pp[i]]] == 0)
		{
			dfs(ey[pp[i]]);
		}
	}
	list[ecnt++] = t;
}

void rdfs(int t, int tar)
{
	int i;
	used[t] = 1;
	for(i=res[t]; i>=0; i--)
	{
		if(ey[pp[i]] != t)
		{
			break;
		}
		if(used[ex[pp[i]]] == 0)
		{
			rdfs(ex[pp[i]], tar);
		}
	}
	root[t] = tar;
}

int main()
{
	int count, n, m, i, ans, tar;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(used, 0, sizeof(used));
		memset(ind, 0, sizeof(ind));
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &ex[i], &ey[i]);
			ind[ey[i]]++;
			pp[i] = i;
		}
		qsort(pp, m, sizeof(int), e_comp);
		memset(es, 0, sizeof(es));
		for(i=0; i<m; i++)
		{
			es[ex[pp[i]]] = i;
		}
		memset(used, 0, sizeof(used));
		for(i=1, ecnt=0; i<=n; i++)
		{
			if(used[i] == 0)
			{
				dfs(i);
			}
		}
		qsort(pp, m, sizeof(int), re_comp);
		memset(res, 0, sizeof(res));
		for(i=0; i<m; i++)
		{
			res[ey[pp[i]]] = i;
		}
		memset(used, 0, sizeof(used));
		for(i=ecnt-1, pcnt=0; i>=0; i--)
		{
			tar = list[i];
			if(used[tar] == 0)
			{
				rdfs(tar, tar);
				poi[pcnt++] = tar;
			}
		}
		memset(used, 0, sizeof(used));
		for(i=0; i<m; i++)
		{
			if(root[ex[i]] != root[ey[i]])
			{
				used[root[ey[i]]] = 1;
			}
		}
		for(i=0, ans=0; i<pcnt; i++)
		{
			ans += !used[root[poi[i]]];
		}
		printf("%d\n", ans);
	}
	return 0;
}
