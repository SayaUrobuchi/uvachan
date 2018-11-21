#include <stdio.h>
#include <string.h>

long long ary[301];
long long dp[31][20], dp2[31][20];

long long mod(long long p, long long q)
{
	if(p >= 0)
	{
		return p%q;
	}
	else
	{
		p = -p;
		p %= q;
		return (q-p)%q;
	}
}

int main()
{
	int cas, n, m, i, j, k, l, p, q;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%lld", &ary[i]);
		}
		printf("SET %d:\n", ++cas);
		for(l=1; l<=m; l++)
		{
			scanf("%d%d", &p, &q);
			memset(dp, 0, sizeof(dp));
			memset(dp2, 0, sizeof(dp2));
			dp[0][0] = dp2[0][0] = 1;
			for(i=0; i<n; i++)
			{
				for(j=0; j<p; j++)
				{
					for(k=1; k<=q; k++)
					{
						dp2[mod((long long)j+ary[i],p)][k] += dp[j][k-1];
					}
				}
				memcpy(dp, dp2, sizeof(dp));
			}
			printf("QUERY %d: %lld\n", l, dp[0][q]);
		}
	}
	return 0;
}
