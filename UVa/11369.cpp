#include <stdio.h>
#include <stdlib.h>

int ary[20005];

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int main()
{
	int count, n, i, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, n, sizeof(int), comp);
		for(i=2, ans=0; i<n; i+=3)
		{
			ans += ary[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
