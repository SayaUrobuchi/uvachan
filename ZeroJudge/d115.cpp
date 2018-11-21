#include <stdio.h>
#include <stdlib.h>

int m, n;
int list[1005], ary[1005];

int comp(const void *p, const void *q)
{
	return *(int*)p>*(int*)q?1:-1;
}

void dfs(int depth, int last)
{
	int i;
	if(depth == m)
	{
		printf("%d", list[0]);
		for(i=1; i<m; i++)
		{
			printf(" %d", list[i]);
		}
		printf("\n");
		return;
	}
	for(i=last; i<n; i++)
	{
		list[depth] = ary[i];
		dfs(depth+1, i+1);
	}
}

int main()
{
	int i;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, n, sizeof(int), comp);
		scanf("%d", &m);
		dfs(0, 0);
		printf("\n");
	}
	return 0;
}
