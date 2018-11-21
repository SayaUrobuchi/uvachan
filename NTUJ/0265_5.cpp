#include <stdio.h>
#include <string.h>

int dp[500001], tbl[5000], list[5000], low, high;

int main()
{
    int n, m, i, j, ln, lim, rate, res;
	while(scanf("%d%d", &n, &m) == 2)
	{
		n *= 1000;
		memset(tbl, 0, sizeof(tbl));
		for(i=0, lim=2147483647; i<m; i++)
		{
			scanf("%d%d", &low, &high);
			for(j=low; j<=high; j++)
			{
				tbl[j] = 1;
			}
			rate = low * 100 / high + 1;
			if(high * rate < lim)
			{
				lim = high * rate;
			}
		}
		for(i=0, ln=0; i<=4500; i++)
		{
			if(tbl[i])
			{
				list[ln++] = i;
			}
		}
		if(lim <= n)
		{
			printf("0\n");
		}
		else
		{
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			for(i=1; i<=n; i++)
			{
				for(j=0; j<ln; j++)
				{
					if(list[j] > i)
					{
						break;
					}
					if(dp[i-list[j]])
					{
						dp[i] = 1;
						res = i;
						break;
					}
				}
			}
			printf("%d\n", n-res);
		}
	}
	return 0;
}
