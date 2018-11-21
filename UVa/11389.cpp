#include <stdio.h>
#include <stdlib.h>

int morning[101];
int evening[101];

int comp1(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int comp2(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int main()
{
	int n, m, o, i, res;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(!n && !m && !o)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &morning[i]);
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &evening[i]);
		}
		qsort(morning, n, sizeof(int), comp1);
		qsort(evening, n, sizeof(int), comp2);
		for(i=0, res=0; i<n; i++)
		{
			if(morning[i] + evening[i] > m)
			{
				res += (morning[i]+evening[i]-m) * o;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
