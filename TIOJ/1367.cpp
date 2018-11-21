#include <stdio.h>
#include <stdlib.h>

int ruby[50005], blue[50005];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, i, j;
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
		for(i=0, j=n-1, ans=0; i<n; i++, j--)
		{
			ans += ruby[i] * blue[j];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
