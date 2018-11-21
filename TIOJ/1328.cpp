#include <stdio.h>
#include <stdlib.h>

int ary[100005];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, i;
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
		printf("%d", ary[0]);
		for(i=1; i<n; i++)
		{
			printf(" %d", ary[i]);
		}
		printf("\n");
	}
	return 0;
}
