#include <stdio.h>
#include <stdlib.h>

int ary[20];
int pairx[20];
int pairy[20];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

double ab(double now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int main()
{
	int cas, n, m, i, j, sum;
	double aver, ans;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<m; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, m, sizeof(int), comp);
		printf("Set #%d\n", ++cas);
		for(i=0, sum=0; i<m-n; i++)
		{
			pairx[i] = ary[i];
			pairy[i] = ary[(m-n)*2-i-1];
			sum += ary[i]+ary[(m-n)*2-i-1];
			printf("%2d: %d %d\n", i, ary[i], ary[(m-n)*2-i-1]);
		}
		for(j=m-1; i<n&&i<m; i++, j--)
		{
			pairx[i] = ary[j];
			pairy[i] = 0;
			sum += ary[j];
			printf("%2d: %d\n", i, ary[j]);
		}
		for(; i<n; i++)
		{
			pairx[i] = 0;
			pairy[i] = 0;
			printf("%2d:\n", i);
		}
		for(i=0, ans=0, aver=sum*1.0/n; i<n; i++)
		{
			/*printf("%.5lf\n", ab(pairx[i]+pairy[i]-aver));*/
			ans += ab(pairx[i]+pairy[i]-aver);
		}
		printf("IMBALANCE = %.5lf\n\n", ans+0.00000001);
	}
	return 0;
}
