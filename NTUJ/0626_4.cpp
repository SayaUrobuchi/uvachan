#include <stdio.h>
#include <string.h>

int ans, len;
int dp[16][32768];
char str[100005];

int main()
{
	int i, j, k, t, lim;
	while(gets(str))
	{
		ans = 2147483647;
		for(i=0, t=0; str[i]; i++)
		{
			t += (str[i]=='1'?(1<<i):0);
		}
		memset(dp, 1, sizeof(dp));
		len = i;
		if(len == 1 && str[0] == '0')
		{
			break;
		}
		dp[0][t] = 0;
		for(i=1, lim=(1<<len); i<=len; i++)
		{
			for(j=0; j<lim; j++)
			{
				dp[i][j] = dp[i-1][j];
			}
			for(j=0; j<lim; j++)
			{
				if(dp[i-1][j] < 300)
				{
					for(k=len-i; k>=0; k--)
					{
						t = (j ^ (((1<<i)-1)<<k));
						if(dp[i][t] > dp[i-1][j] + i)
						{
							dp[i][t] = dp[i-1][j] + i;
						}
					}
				}
			}
		}
		printf("%d\n", dp[len][0]);
	}
	return 0;
}
