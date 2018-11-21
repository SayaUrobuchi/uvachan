#include <stdio.h>
#include <stdlib.h>

int ary[1000];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int cas, n, m, i, j, k, area;
	double height;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0, j=n*m; i<j; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, j, sizeof(int), comp);
		scanf("%d", &m);
		height = ary[0];
		for(i=0, area=0; i<j; i=k)
		{
			for(k=i+1, area+=100; k<j; k++, area+=100)
			{
				if(ary[i] != ary[k])
				{
					break;
				}
			}
			if(m > area * (ary[k]-ary[i]))
			{
				m -= area * (ary[k]-ary[i]);
				height += ary[k] - ary[i];
			}
			else
			{
				break;
			}
		}
		height += (double)m / area;
		printf("Region %d\n", ++cas);
		printf("Water level is %.2lf meters.\n", height);
		printf("%.2lf percent of the region is under water.\n\n", k*100.0/j);
	}
	return 0;
}
