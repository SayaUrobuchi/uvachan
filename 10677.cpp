#include <stdio.h>

int dp[4], dp2[4], ary[4];

int main()
{
	int count, i, j, k, tmp, n1, n2;
	dp[0] = 1;
	dp2[0] = 1;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &dp[1], &dp2[1], &i, &j);
		for(k=2; k<4; k++)
		{
			dp[k] = dp[k-1] * dp[1];
			dp2[k] = dp2[k-1] * dp2[1];
		}
		for(i--; j>i; j--)
		{
			tmp = j;
			for(k=0; tmp; k++, tmp/=dp[1])
			{
				ary[k] = tmp % dp[1];
			}
			n1 = 0;
			n2 = 0;
			for(k--; k>-1; k--)
			{
				n1 += dp[k] * ary[k];
				n2 += dp2[k] * ary[k];
			}
			if(!(n2 % n1))
			{
				printf("%d\n", j);
				break;
			}
		}
		if(j == i)
		{
			printf("Non-existent.\n");
		}
	}
	return 0;
}
