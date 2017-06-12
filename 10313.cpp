#include <stdio.h>

long long dp[301][301];
char str[100];

int main()
{
	int n, i, j, k, s, l1, l2;
	long long ans;
	dp[0][0] = 1;
	for(i=1; i<=300; i++)
	{
		for(j=i; j<=300; j++)
		{
			for(k=1; k<=300; k++)
			{
				dp[j][k] += dp[j-i][k-1];
			}
		}
	}
	while(gets(str))
	{
		s = sscanf(str, "%d%d%d", &n, &l1, &l2);
		if(s == 1)
		{
			for(i=0, ans=0; i<=300; i++)
			{
				ans += dp[n][i];
			}
		}
		else if(s == 2)
		{
			if(l1 > 300)
			{
				l1 = 300;
			}
			for(i=0, ans=0; i<=l1; i++)
			{
				ans += dp[n][i];
			}
		}
		else
		{
			if(l2 > 300)
			{
				l2 = 300;
			}
			for(i=l1, ans=0; i<=l2; i++)
			{
				ans += dp[n][i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
