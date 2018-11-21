#include <stdio.h>
#include <string.h>

int dp[1001], dp2[1001], tbl[1001];
int change[6] = {5, 10, 20, 50, 100, 200};

int main()
{
	int coin[6], i, j, tmp, tmp2, sum, pay, min;
	double in;
	memset(dp, 0, sizeof(dp));
	for(i=5; i>-1; i--)
	{
		tmp = change[i];
		dp[tmp] = 1;
		for(j=tmp+5; j<1001; j+=5)
		{
			if(dp[j-tmp])
			{
				if(dp[j] > dp[j-tmp] + 1 || !dp[j])
				{
					dp[j] = dp[j-tmp] + 1;
				}
			}
		}
	}
	while(1)
	{
		for(i=0, sum=0; i<6; i++)
		{
			scanf("%d", &coin[i]);
			sum += coin[i];
		}
		if(!sum)
		{
			break;
		}
		scanf("%lf", &in);
		in *= 100;
		pay = (int)(in + 0.5);
		memset(dp2, 0, sizeof(dp2));
		for(i=5; i>-1; i--)
		{
			if(coin[i])
			{
				memset(tbl, 0, sizeof(tbl));
				tmp2 = coin[i];
				tmp = change[i];
				tbl[tmp] = 1;
				dp2[tmp] = 1;
				for(j=tmp+5; j<1001; j+=5)
				{
					if(dp2[j-tmp] && tbl[j-tmp] < tmp2)
					{
						if(dp2[j] > dp2[j-tmp] + 1 || !dp2[j])
						{
							dp2[j] = dp2[j-tmp] + 1;
							tbl[j] = tbl[j-tmp] + 1;
						}
					}
				}
			}
		}
		for(i=pay, min=0; i<1001; i+=5)
		{
			if(dp2[i])
			{
				tmp = i - pay;
				if(dp[tmp] + dp2[i] < min || !min)
				{
					min = dp[tmp] + dp2[i];
				}
			}
		}
		printf("%3d\n", min);
	}
    return 0;
}
