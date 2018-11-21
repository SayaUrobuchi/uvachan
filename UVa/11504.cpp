#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ex[100005], ey[100005], es[100005], pp[100005], used[100005], ind[100005];

int e_comp(const void *p, const void *q)
{
	return ex[*(int*)p] - ex[*(int*)q];
}

void dfs(int t)
{
	int i, tar;
	for(i=es[t]; i>=0; i--)
	{
		if(ex[pp[i]] != t)
		{
			break;
		}
		tar = ey[pp[i]];
		if(used[tar] == 0)
		{
			used[tar] = 1;
			dfs(tar);
		}
	}
}

int main()
{
	int count, n, m, i, ans;
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
		for(i=1; i<=n; i++)
		{
			if(ind[i] == 0)
			{
				used[i] = 1;
				dfs(i);
				used[i] = 0;
			}
		}
		for(i=1; i<=n; i++)
		{
			if(used[i] == 0 && ind[i])
			{
				used[i] = 1;
				dfs(i);
				used[i] = 0;
			}
		}
		for(i=1, ans=0; i<=n; i++)
		{
			ans += !used[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
