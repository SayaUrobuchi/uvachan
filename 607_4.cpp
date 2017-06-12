#include <stdio.h>
#include <string.h>

#define N 602001

int n, m, o, l1, l2;
int ary[1005];
int tbl[N];
int tbl2[N];
long long dp[N];

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
	int cas, i, j, k, s, t, c, now;
	int *list, *list2, *temp;
	long long ans, inf;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		scanf("%d%d", &m, &o);
		for(i=0, c=1, now=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
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
		l1 = l2 = 0;
		list = tbl;
		list2 = tbl2;
		list[l1++] = 0;
		for(i=0; i<n; i++)
		{
			for(j=0; j<l1; j++)
			{
				t = list[j] / (m+1);
				if(t < c)
				{
					s = t * (m+1);
					k = list[j] - s;
					if(k + ary[i] <= m)
					{
						if(dp[s+k] < dp[s+k+ary[i]])
						{
							if(dp[s+k+ary[i]] == inf)
							{
								list2[l2++] = s + k + ary[i];
							}
							dp[s+k+ary[i]] = dp[s+k];
						}
					}
					if(dp[s+k] + deal(k) < dp[s+m+1+ary[i]])
					{
						if(dp[s+m+1+ary[i]] == inf)
						{
							list2[l2++] = s + m + 1 + ary[i];
						}
						dp[s+m+1+ary[i]] = dp[s+k] + deal(k);
					}
				}
				dp[s+k] = inf;
			}
			l1 = l2;
			temp = list;
			list = list2;
			list2 = temp;
			l2 = 0;
		}
		for(j=0, ans=inf; j<l1; j++)
		{
			t = list[j] / (m+1);
			if(t >= c)
			{
				continue;
			}
			s = t * (m+1);
			k = list[j] - s;
			if(dp[s+k] < ans)
			{
				ans = dp[s+k];
			}
		}
		if(cas)
		{
			printf("\n");
		}
		printf("Case %d:\n", ++cas);
		printf("Minimum number of lectures: %d\n", c);
		printf("Total dissatisfaction index: %I64d\n", ans);
	}
	return 0;
}
