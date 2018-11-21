#include <stdio.h>
#include <string.h>

int dp[500001], l1[500001], l2[500001], low[105], high[105], *p, *q;

int main()
{
    int n, m, i, j, k, l, len, lim, rate, *tmp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		n *= 1000;
		for(i=0, lim=2147483647; i<m; i++)
		{
			scanf("%d%d", &low[i], &high[i]);
			rate = low[i] * 100 / high[i] + 1;
			if(high[i] * rate < lim)
			{
				lim = high[i] * rate;
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
			p = l1;
			q = l2;
			for(i=1; i<=n; i++)
			{
				p[i-1] = i;
			}
			len = n;
			for(i=0; i<m; i++)
			{
				for(j=0, l=0; j<len; j++)
				{
					if(p[j] >= low[i])
					{
						for(k=low[i]; k<=high[i]&&p[j]>=k; k++)
						{
							if(dp[p[j]-k])
							{
								dp[p[j]] = 1;
								break;
							}
						}
						if(dp[p[j]])
						{
							continue;
						}
					}
					q[l++] = p[j];
				}
				len = l;
				tmp = p;
				p = q;
				q = tmp;
				if(dp[n])
				{
					break;
				}
			}
			for(i=n; i>=0; i--)
			{
				if(dp[i])
				{
					printf("%d\n", n-i);
					break;
				}
			}
		}
	}
	return 0;
}
