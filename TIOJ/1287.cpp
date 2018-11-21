#include <stdio.h>
#include <stdlib.h>

int ary[1000005];

int comp(const void *p, const void *q)
{
	return *(int*)p > *(int*)q ? 1 : -1;
}

int main()
{
	int n, i;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, n, sizeof(int), comp);
		printf("%d", ary[0]);
		for(i=1; i<n; i++)
		{
			printf(" %d", ary[i]);
		}
		printf("\n");
	}
	return 0;
}
