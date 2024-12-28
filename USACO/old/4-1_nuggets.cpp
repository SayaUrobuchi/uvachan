/*
	ID: sa072682
	LANG: C
	TASK: nuggets
*/
#include <stdio.h>

int ary[10], list[10], dp[1000000];

int getgcd(int p, int q)
{
	if(p % q)
	{
		return getgcd(q, p%q);
	}
	return q;
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, m, i, lim, gcd, ans, temp;
	freopen("nuggets.in", "r", stdin);
	freopen("nuggets.out", "w", stdout);
	scanf("%d", &m);
	for(i=0, lim=0; i<m; i++)
	{
		scanf("%d", &ary[i]);
		if(i)
		{
			gcd = getgcd(gcd, ary[i]);
		}
		else
		{
			gcd = ary[i];
		}
		lim = max(lim, ary[i]);
	}
	if(gcd != 1)
	{
		printf("0\n");
	}
	else
	{
		for(n=1, ans=0; n<=lim||(n>lim&&dp[n-1]-dp[n-lim-1]!=lim); n++)
		{
			dp[n] = 2000000000;
			for(i=0; i<m; i++)
			{
				for(; dp[list[i]]+ary[i]<=dp[n-1]; list[i]++);
				temp = dp[list[i]] + ary[i];
				if(dp[n] > temp)
				{
					dp[n] = temp;
				}
			}
			if(dp[n] - 1 > dp[n-1])
			{
				ans = dp[n] - 1;
			}
		}
		printf("%d\n", ans);
	}
	scanf(" ");
	return 0;
}
