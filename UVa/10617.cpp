#include <stdio.h>

long long dp[60][60];
char str[61];

long long calc(int l, int r)
{
	if(l > r)
	{
		return 0;
	}
	return dp[l][r];
}

int main()
{
	int count, n, i, j;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		for(n=0; str[n]; n++)
		{
			for(i=n; i>-1; i--)
			{
				if(str[i] == str[n])
				{
					dp[i][n] = calc(i+1, n-1) + 1;
				}
				else
				{
					dp[i][n] = 0;
				}
				dp[i][n] += calc(i+1, n);
				dp[i][n] += calc(i, n-1);
				dp[i][n] -= calc(i+1, n-1);
			}
		}
		printf("%lld\n", dp[0][n-1]);
	}
	return 0;
}
