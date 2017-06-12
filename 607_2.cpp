#include <stdio.h>
#include <string.h>

#define N 502001

int n, m, o;
int ary[1005];
int dp[N];
int dp2[N];

int deal(int now)
{
	now = m - now;
	if(!now)
	{
		return 0;
	}
	else if(now <= 10)
	{
		return -o;
	}
	now -= 10;
	return now * now;
}

int main()
{
	int cas, i, j, k, s, c, now, sum, inf, ans;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		scanf("%d%d", &m, &o);
		for(i=0, c=1, now=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
			if(now + ary[i] > m)
			{
				now = ary[i];
				c++;
			}
			else
			{
				now += ary[i];
			}
		}
		memset(dp, 100, sizeof(dp));
		inf = dp[0];
		dp[0] = 0;
		for(i=0; i<n; i++)
		{
			for(j=c-1, s=j*(m+1); j>=0; j--, s-=m+1)
			{
				for(k=m; k>=0; k--)
				{
					if(dp[s+k] < inf)
					{
						if(k + ary[i] <= m)
						{
							if(dp[s+k] < dp[s+k+ary[i]])
							{
								dp[s+k+ary[i]] = dp[s+k];
							}
						}
						if(dp[s+k] + deal(k) < dp[s+m+1+ary[i]])
						{
							dp[s+m+1+ary[i]] = dp[s+k] + deal(k);
						}
						dp[s+k] = inf;
					}
				}
			}
			sum -= ary[i];
		}
		for(i=0, c--, s=c*(m+1), ans=inf; i<=m; i++)
		{
			if(dp[s+i] < inf)
			{
				if(dp[s+i] + deal(i) < ans)
				{
					ans = dp[s+i] + deal(i);
				}
			}
		}
		if(cas)
		{
			printf("\n");
		}
		printf("Case %d:\n", ++cas);
		printf("Minimum number of lectures: %d\n", c+1);
		printf("Total dissatisfaction index: %d\n", ans);
	}
	return 0;
}
