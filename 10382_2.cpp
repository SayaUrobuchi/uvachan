#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double ary[10000][2];

int comp(const void *p, const void *q)
{
	return *(double*)p - *(double*)q;
}

int main()
{
	int i;
	double n, l, w, j, low, x, r, ans, maxi;
	double left, tmp, w2, max;
	while(scanf("%lf%lf%lf", &n, &l, &w) == 3)
	{
		w2 = w / 2.0;
		w2 *= w2;
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &ary[i][0], &ary[i][1]);
		}
		qsort(ary, n--, sizeof(ary[0]), comp);
		low = -1.0;
		left = 0.0;
		ans = 0.0;
		while(1)
		{
			max = left;
			for(i=n; i>low; i--)
			{
				x = ary[i][0];
				r = ary[i][1];
				if(w2 + (x-left) * (x-left) <= r * r)
				{
					tmp = x + sqrt(r * r - w2);
					if(tmp > max)
					{
						max = tmp;
						maxi = i;
					}
				}
			}
			if(max == left)
			{
				ans = -1.0;
				break;
			}
			low = maxi;
			left = max;
			ans++;
			if(left >= l)
			{
				break;
			}
		}
		printf("%.0f\n", ans);
	}
	return 0;
}
