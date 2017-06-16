#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[128], y[128], idx[128];

int comp(const void *p, const void *q)
{
	return x[*(int*)q] > x[*(int*)p] ? 1 : -1;
}

int main()
{
	int count, n, i, lastx, lasty, maxy, yy;
	double res, xx;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
			idx[i] = i;
		}
		qsort(idx, n, sizeof(idx[0]), comp);
		res = 0;
		for (i=0, lastx=0, lasty=0, maxy=0; i<n; i++)
		{
			if (y[idx[i]] > maxy)
			{
				yy = maxy - y[idx[i]];
				xx = (lastx-x[idx[i]])/(double)(lasty-y[idx[i]])*yy;
				res += sqrt(xx*xx+yy*yy);
				maxy = y[idx[i]];
			}
			lasty = y[idx[i]];
			lastx = x[idx[i]];
		}
		printf("%.2f\n", res);
	}
	return 0;
}
