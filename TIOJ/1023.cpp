#include <stdio.h>
#include <stdlib.h>

int ruby[50001], blue[50001];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int count, n, i;
	long long ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ruby[i]);
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &blue[i]);
		}
		qsort(ruby, n, sizeof(int), comp);
		qsort(blue, n, sizeof(int), comp);
		for(i=0, ans=0; i<n; i++)
		{
			ans += ruby[i] * blue[i];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
