#include <stdio.h>
#include <stdlib.h>

int ary[20];

int comp(const void *p, const void *q)
{
	return *(int*)p > *(int*)q ? 1 : -1;
}

int main()
{
	int cas, count, n, i;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, n, sizeof(ary[0]), comp);
		printf("Case %d: %d\n", ++cas, ary[n>>1]);
	}
	return 0;
}
