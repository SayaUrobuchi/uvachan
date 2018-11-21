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
	while(scanf("%d", &n) == 1)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		scanf("%d", &m);
		qsort(ary+1, n, sizeof(int), comp);
		printf("%d\n", ary[m]);
	}
	return 0;
}
