#include <stdio.h>

#define N 512

int n;
int ary[N];
int dpuu[N], dpud[N], dpdu[N], dpdd[N];

int main()
{
	int m, i, j, k, t, ans;
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
		for (k=n-1; k>=0; k--)
		{
			dpuu[k] = 1;
			dpud[k] = 1;
			dpdu[k] = 1;
			dpdd[k] = 1;
			/* uu: >= now, ud: < now
			 * du: > now, dd: <= now
			 * but that's only how to consider things == now; 
			 * if things != now it's not possible duplicated between u and d, 
			 * so consider both (uu, du) and (ud, dd)
			 * ex. 1 2 2 1, it's fine to have 2 strictly larger than 1, 
			 * pair to not strictly less than 1, 
			 * but second 2 can be not strictly larger than 2, 
			 * because it's impossible to be duplicated with 1 == now
			 */
			for (i=k+1; i<n; i++)
			{
				if (ary[i] > ary[k])
				{
					if (dpuu[i]+1 > dpuu[k])
					{
						dpuu[k] = dpuu[i]+1;
					}
					if (dpdu[i]+1 > dpuu[k])
					{
						dpuu[k] = dpdu[i]+1;
					}
					if (dpuu[i]+1 > dpdu[k])
					{
						dpdu[k] = dpuu[i]+1;
					}
					if (dpdu[i]+1 > dpdu[k])
					{
						dpdu[k] = dpdu[i]+1;
					}
				}
				else if (ary[i] < ary[k])
				{
					if (dpud[i]+1 > dpud[k])
					{
						dpud[k] = dpud[i]+1;
					}
					if (dpdd[i]+1 > dpud[k])
					{
						dpud[k] = dpdd[i]+1;
					}
					if (dpud[i]+1 > dpdd[k])
					{
						dpdd[k] = dpud[i]+1;
					}
					if (dpdd[i]+1 > dpdd[k])
					{
						dpdd[k] = dpdd[i]+1;
					}
				}
				else
				{
					if (dpuu[i]+1 > dpuu[k])
					{
						dpuu[k] = dpuu[i]+1;
					}
					if (dpdd[i]+1 > dpdd[k])
					{
						dpdd[k] = dpdd[i]+1;
					}
				}
			}
			if (dpuu[k] + dpud[k] - 1 > ans)
			{
				ans = dpuu[k] + dpud[k] - 1;
			}
			if (dpdu[k] + dpdd[k] - 1 > ans)
			{
				ans = dpdu[k] + dpdd[k] - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
