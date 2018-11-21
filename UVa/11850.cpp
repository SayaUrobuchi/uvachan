#include <stdio.h>
#include <stdlib.h>

int a[10005];

int comp(const void *p, const void *q)
{
	return *(int*)p<*(int*)q?-1:1;
}

int main()
{
	int n, i, j;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
		}
		qsort(a, n, sizeof(a[0]), comp);
		for(i=0, j=0; i<n; i++)
		{
			if(a[i]-j > 200)
			{
				break;
			}
			j = a[i];
		}
		if(i < n || 1422-j > 100)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("POSSIBLE\n");
		}
	}
	return 0;
}
