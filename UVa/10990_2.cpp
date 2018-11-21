#include <stdio.h>
#include <math.h>

int prime[4791], ary[100];
int dp[2000001];

char dfs(long long now, int res, int last, int n)
{
	int i;
	if(now > 2000000)
	{
		return 1;
	}
	dp[now] = res;
	for(i=last; i<n; i++)
	{
		if(dfs(now*ary[i], res*ary[i], i, n))
		{
			break;
		}
	}
	return 0;
}

int main()
{
	int count, i, j, k, l, chk, tmp, res;
	dp[2] = 1;
	ary[0] = 2;
	dfs(2, 1, 0, 1);
	dp[3] = 2;
	prime[0] = 3;
	ary[0] = 3;
	dfs(3, 2, 0, 1);
	for(i=4, l=1; i<46341; i++)
	{
		if(!dp[i])
		{
			j = 0;
			res = 1;
			chk = i;
			if(!(i % 2))
			{
				ary[j++] = 2;
				chk /= 2;
			}
			for(k=0, tmp=prime[k]; tmp*tmp<=chk; k++, tmp=prime[k])
			{
				if(!(chk % tmp))
				{
					ary[j++] = tmp;
					res *= tmp - 1;
					chk /= tmp;
				}
			}
			if(chk > 1)
			{
                if(chk == i)
				{
					prime[l++] = i;
				}
				ary[j++] = chk;
				res *= chk - 1;
			}
			dfs(i, res, 0, j);
		}
	}
	for(; i<2000001; i++)
	{
		if(!dp[i])
		{
			j = 0;
			res = 1;
			chk = i;
			if(!(i % 2))
			{
				ary[j++] = 2;
				chk /= 2;
			}
			for(k=0, tmp=prime[k]; tmp*tmp<=chk; k++, tmp=prime[k])
			{
				if(!(chk % tmp))
				{
					ary[j++] = tmp;
					res *= tmp - 1;
					chk /= tmp;
				}
			}
			if(chk > 1)
			{
				ary[j++] = chk;
				res *= chk - 1;
			}
			dfs(i, res, 0, j);
		}
	}
	for(i=2; i<2000001; i++)
	{
		dp[i] = dp[dp[i]] + 1;
	}
	for(i=2; i<2000001; i++)
	{
		dp[i] += dp[i-1];
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &i, &j);
		printf("%d\n", dp[j] - dp[i-1]);
	}
	return 0;
}
