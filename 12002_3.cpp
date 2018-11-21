#include <stdio.h>

#define N 512

int n;
int ary[N];
int dpuu[N], dpdd[N];

int main()
{
	int m, i, j, k, tuu, tdd, tud, tdu, uu, dd, ud, du, ans;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		ans = 1;
		uu = dd = -1;
		for (k=n-1; k>=0; k--)
		{
			for (i=uu; i>=0; i--)
			{
				if (dpuu[i] <= ary[k])
				{
					break;
				}
			}
			tuu = i+1;
			if (tuu > uu)
			{
				uu = tuu;
			}
			dpuu[tuu] = ary[k];
			for (; i>=0; i--)
			{
				if (dpuu[i] < ary[k])
				{
					break;
				}
			}
			tdu = i+1;
			/* -------- */
			for (i=dd; i>=0; i--)
			{
				if (dpdd[i] >= ary[k])
				{
					break;
				}
			}
			tdd = i+1;
			if (tdd > dd)
			{
				dd = tdd;
			}
			dpdd[tdd] = ary[k];
			for (; i>=0; i--)
			{
				if (dpdd[i] > ary[k])
				{
					break;
				}
			}
			tud = i+1;
			if (tuu + tud + 1 > ans)
			{
				ans = tuu + tud + 1;
			}
			if (tdu + tdd + 1 > ans)
			{
				ans = tdu + tdd + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
