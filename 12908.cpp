#include <stdio.h>

int main()
{
	int n, l, r, c, k, ans, total;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		for (l=1, r=20005; l<=r; )
		{
			c = ((l+r)>>1);
			k = (((c+1)*c)>>1);
			if (k > n)
			{
				ans = k-n;
				total = c;
				r = c-1;
			}
			else
			{
				l = c+1;
			}
		}
		printf("%d %d\n", ans, total);
	}
	return 0;
}
