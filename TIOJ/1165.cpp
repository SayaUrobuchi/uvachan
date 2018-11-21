#include <stdio.h>
#include <stdlib.h>

int a[3];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	while(scanf("%d%d%d", &a[0], &a[1], &a[2]) == 3)
	{
		qsort(a, 3, sizeof(int), comp);
		printf("%s\n", a[0]+a[1]==a[2]?"Good Pair":"Not Good Pair");
	}
	return 0;
}
