#include <stdio.h>
#include <string.h>

long long dp[16][16];
char str[1000];

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int transform(char ch)
{
	if(ch <= '9')
	{
		return ch - 48;
	}
	return ch - 55;
}

int main()
{
	int i, j, k, len;
	long long sum;
	while(scanf("%s", str) == 1)
	{
		memset(dp, 0, sizeof(dp));
		len = strlen(str);
		for(i=1; i<=len; i++)
		{
			if(str[i-1] == '?')
			{
				for(j=1; j<=len; j++)
				{
					if(i == 1)
					{
						dp[i][j] = 1;
					}
					else
					{
						for(k=1; k<=len; k++)
						{
							if(ab(k-j) > 1)
							{
								dp[i][j] += dp[i-1][k];
							}
						}
					}
				}
			}
			else
			{
				j = transform(str[i-1]);
				if(i == 1)
				{
					dp[i][j] = 1;
				}
				else
				{
					for(k=1; k<=len; k++)
					{
						if(ab(k-j) > 1)
						{
							dp[i][j] += dp[i-1][k];
						}
					}
				}
			}
		}
		for(i=1, sum=0; i<=len; i++)
		{
			sum += dp[len][i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
