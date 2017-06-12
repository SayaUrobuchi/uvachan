#include <stdio.h>

int dp[10001];

int main()
{
	int n, b, i, j, tmp, sum, ans;
	for(i=2; i<10001; i++)
	{
		if(!dp[i])
		{
			for(j=1, n=i; j<=i && n<10001; j++, n+=i)
			{
				dp[n] = i;
			}
		}
	}
	while(scanf("%d%d", &n, &b) == 2)
	{
		if(!n && !b)
		{
			break;
		}
		tmp = dp[b];
		sum = 1;
		ans = 0;
		for(i=tmp; i<=n; i+=tmp)
		{
			ans += tmp * sum;
			j = i;
			while(1)
			{
				if(j % tmp)
				{
					break;
				}
				sum++;
				j /= tmp;
			}
		}
		ans += (tmp - n + i) * tmp;
		printf("%d\n", ans);
	}
	return 0;
}
