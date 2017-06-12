#include <stdio.h>
#include <stdlib.h>

int front[10];
double ary[100];

int comp(const void *p, const void *q)
{
	if(*(double*)p > *(double*)q)
	{
		return 1;
	}
	return -1;
}

double max(double i, double j)
{
	if(i > j)
	{
		return i;
	}
	return j;
}

int main()
{
	int f, r, i, j, k, in;
	double ans;
	while(scanf("%d", &f) == 1)
	{
		if(!f)
		{
			break;
		}
		scanf("%d", &r);
		for(i=0; i<f; i++)
		{
			scanf("%d", &front[i]);
		}
		for(i=0, k=0; i<r; i++)
		{
			scanf("%d", &in);
			for(j=0; j<f; j++)
			{
				ary[k++] = (double)in / front[j];
			}
		}
		qsort(ary, k, sizeof(double), comp);
		for(i=1, ans=0; i<k; i++)
		{
			ans = max(ary[i]/ary[i-1], ans);
		}
		printf("%.2f\n", ans);
	}
	return 0;
}
