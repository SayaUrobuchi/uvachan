#include <stdio.h>
#include <stdlib.h>

#define N 1000

double pl[N], pr[N];
double rate[N];
double ary[N<<1];

int comp(const void *p, const void *q)
{
	if(*(double*)p > *(double*)q)
	{
		return 1;
	}
	return -1;
}

int main()
{
	int count, n, m, i, j;
	double light, xcor;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, m=0; i<n; i++)
		{
			scanf("%lf%*lf%lf%*lf%lf", &pl[i], &pr[i], &rate[i]);
			ary[m++] = pl[i];
			ary[m++] = pr[i];
			if(pl[i] > pr[i])
			{
				xcor = pl[i];
				pl[i] = pr[i];
				pr[i] = xcor;
			}
		}
		qsort(ary, m, sizeof(double), comp);
		printf("%d\n", m+1);
		printf("-inf %.3lf 1.000\n", ary[0]);
		for(i=1; i<m; i++)
		{
			for(j=0, xcor=(ary[i-1]+ary[i])/2.0, light=1.0; j<n; j++)
			{
				if(xcor > pl[j] && xcor < pr[j])
				{
					light *= rate[j];
				}
			}
			printf("%.3lf %.3lf %.3lf\n", ary[i-1], ary[i], light);
		}
		printf("%.3lf +inf 1.000\n", ary[m-1]);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
