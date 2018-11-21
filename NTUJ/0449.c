#include <stdio.h>
#include <stdlib.h>

int px[205], py[205];
double ary[40005];

int comp(const void *p, const void *q)
{
	return *(double*)p > *(double*)q ? -1 : 1;
}

int ab(int p)
{
	return p > 0 ? p : -p;
}

int main()
{
	int n, i, j, m, ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=0, m=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			for(j=0; j<i; j++)
			{
				if(py[i] - py[j])
				{
					ary[m++] = (px[i]-px[j]) / (double)(py[i]-py[j]);
				}
				else
				{
					ary[m++] = 1e10;
				}
			}
		}
		qsort(ary, m, sizeof(double), comp);
		for(i=0, ans=m; i<m; i=j)
		{
			for(j=i+1; j<m; j++)
			{
				if(ary[i] - ary[j] > 1e-10)
				{
					break;
				}
			}
			ans -= j-i-1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
