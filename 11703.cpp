#include <stdio.h>
#include <math.h>

int dp[1000005];

int main()
{
	int i;
	dp[0] = 1;
	for(i=1; i<=1000000; i++)
	{
		dp[i] = (dp[(int)(i-sqrt(i)+1e-8)]+dp[(int)(log(i)+1e-8)]+dp[(int)(i*sin(i)*sin(i)+1e-8)])%1000000;
	}
	while(scanf("%d", &i) == 1)
	{
		if(i == -1)
		{
			break;
		}
		printf("%d\n", dp[i]);
	}
	return 0;
}
