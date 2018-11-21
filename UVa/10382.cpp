#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int ary[10000][2];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, l, w, i, j, low, x, r, ans, maxi;
	double left, tmp, w2, max;
	while(scanf("%d%d%d", &n, &l, &w) == 3)
	{
		w2 = w / 2.0;
		w2 *= w2;
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i][0], &ary[i][1]);
		}
		qsort(ary, n--, 8, comp);
		low = -1;
		left = 0;
		ans = 0;
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
				ans = -1;
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
		printf("%d\n", ans);
	}
	return 0;
}
