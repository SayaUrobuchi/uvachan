#include <stdio.h>
#include <stdlib.h>

int ary[1000005];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, m, i;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary+1, n, sizeof(int), comp);
		printf("%d", ary[1]);
		for(i=2; i<=m; i++)
		{
			printf(" %d", ary[i]);
		}
		printf("\n");
	}
	return 0;
}
