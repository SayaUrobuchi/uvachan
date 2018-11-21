#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double ary[100005];

int comp(const void *p, const void *q)
{
	return *(double*)p > *(double*)q ? 1 : -1;
}

double hei(double a, double b, double c)
{
	double s;
	s = (a+b+c)/2;
	return s*(s-a)*(s-b)*(s-c);
}

int main()
{
	int count, n, i, j, k;
	double t, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%lf", &ary[i]);
		}
		qsort(ary, n, sizeof(ary[0]), comp);
		ans = 0;
		for(i=n; i>=2&&i>=n-60; i--)
		{
			for(j=i-1; j>=1&&j>=n-70; j--)
			{
				k = j-1;
				if(ary[k]+ary[j] > ary[i])
				{
					t = hei(ary[k], ary[j], ary[i]);
					if(t > ans)
					{
						ans = t;
					}
					break;
				}
			}
		}
		printf("%.2lf\n", sqrt(ans));
	}
	return 0;
}
