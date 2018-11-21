#include <stdio.h>
#include <stdlib.h>

int ary1[105], ary2[105];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, m, o, i, j, res;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary1[i]);
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary2[i]);
		}
		qsort(ary1, n, sizeof(int), comp);
		qsort(ary2, n, sizeof(int), comp);
		for(i=0, j=n-1, res=0; i<n; i++, j--)
		{
			if(ary1[i]+ary2[j] > m)
			{
				res += (ary1[i]+ary2[j]-m) * o;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
