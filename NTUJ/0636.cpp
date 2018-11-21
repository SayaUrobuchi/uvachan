#include <stdio.h>
#include <string.h>

int ans, n;
int dp[10000][3], used[10000][3], tim[3][12];

int min(int p, int q)
{
	return p<q ? p : q;
}

int get_num(int stat)
{
	int i, res;
	for(i=0, res=0; i<n; i++)
	{
		res += !!(stat&(1<<i));
	}
	return res;
}

int calc(int stat, int tar, int dep)
{
	int i, tt;
	if(used[stat][tar])
	{
		return dp[stat][tar];
	}
	used[stat][tar] = 1;
	if(stat == 0)
	{
		return dp[stat][tar] = 0;
	}
	dp[stat][tar] = 2147483647;
	for(i=0; i<n; i++)
	{
		if(stat & (1<<i))
		{
			tt = min(calc(stat-(1<<i), (tar+1)%3, dep+1), calc(stat-(1<<i), (tar+2)%3, dep+1));
			if(tt + tim[tar][i] < dp[stat][tar])
			{
				dp[stat][tar] = tt+tim[tar][i];
			}
		}
	}
	return dp[stat][tar];
}

int main()
{
	int count, i, j, lim, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(j=0; j<3; j++)
		{
			for(i=0; i<n; i++)
			{
				scanf("%d", &tim[j][i]);
			}
		}
		ans = 0;
		memset(used, 0, sizeof(used));
		calc((1<<n)-1, 0, 0);
		calc((1<<n)-1, 1, 0);
		calc((1<<n)-1, 2, 0);
		for(i=0, lim=(1<<n); i<lim; i++)
		{
			if(dp[i][0] <= 280 || dp[i][1] <= 280 || dp[i][2] <= 280)
			{
				temp = get_num(i);
				if(temp > ans)
				{
					ans = temp;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
