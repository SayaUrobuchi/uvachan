#include <stdio.h>

const int M = 5;
const int RANGE = 1000000005;

int ary[5], xx[1000005], yy[1000005];

int main()
{
	int n, k, i, j, mid, res, z, l, ans;
	long long x, y;
	while (scanf("%d", &k) == 1)
	{
		for (i=0; i<M; i++)
		{
			scanf("%d", &ary[i]);
		}
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &xx[i], &yy[i]);
		}
		for (i=-RANGE, j=RANGE; i<=j; )
		{
			mid = ((i+j)/2);
			res = 0;
			for (l=0; l<n; l++)
			{
				y = mid;
				for (z=4, x=xx[l]; z>=0; z--, x*=xx[l])
				{
					y += ary[z]*x;
				}
				if (y <= yy[l])
				{
					res++;
				}
			}
			if (res >= k)
			{
				i = mid+1;
				ans = mid;
			}
			else
			{
				j = mid-1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
