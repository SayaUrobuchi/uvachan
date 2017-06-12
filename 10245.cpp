#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double x[10001], y[10001];
int index[10001];

int comp(const void *p, const void *q)
{
	if(x[*(int*)p] > x[*(int*)q])
	{
		return 1;	
	}
	return -1;
}

double getdis(double x, double y)
{
	return sqrt(x*x+y*y);
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
	int n, i, j, p, q;
	double temp, ans;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &x[i], &y[i]);
			index[i] = i;
		}
		qsort(index, n, sizeof(int), comp);
		for(i=0, ans=2147483647; i<n; i++)
		{
			p = index[i];
			for(j=i+1; j<n; j++)
			{
				q = index[j];
				if(x[q] - x[p] > ans)
				{
					break;
				}
				if(ab(y[q] - y[p]) < ans)
				{
					temp = getdis(x[q]-x[p], y[q]-y[p]);
					if(temp < ans)
					{
						ans = temp;
					}
				}
			}
		}
		if(ans > 10000.0)
		{
			printf("INFINITY\n");
		}
		else
		{
			printf("%.4lf\n", ans);
		}
	}
	return 0;
}
