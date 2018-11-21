#include <stdio.h>
#include <stdlib.h>

const int M = 5;
const int RANGE = 1000000005;

int ary[5], xx[1000005];
int yres[1000005];

int comp(const void *p, const void *q)
{
	return *(int*)p > *(int*)q ? -1 : 1;
}

int main()
{
	int n, k, i, j, mid, res, z, l, ans;
	long long x, y, xx, yy;
	while (scanf("%d", &k) == 1)
	{
		for (i=0; i<M; i++)
		{
			scanf("%d", &ary[i]);
		}
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d%lld", &xx, &yy);
			y = 0;
			for (z=4, x=xx; z>=0; z--, x*=xx)
			{
				y += ary[z]*x;
			}
			yres[i] = yy-y;
		}
		qsort(yres, n, sizeof(int), comp);
		printf("%d\n", yres[k-1]);
	}
	return 0;
}
