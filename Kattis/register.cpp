#include <iostream>

int ary[16];
int dp[16] = {1, 2, 3, 5, 7, 11, 13, 17, 19};

int main()
{
	int i, ans;
	for (i=1; i<=8; i++)
	{
		dp[i] *= dp[i-1];
	}
	while (scanf("%d", &ary[0]) == 1)
	{
		for (i=1, ans=dp[8]-1-ary[0]; i<8; i++)
		{
			scanf("%d", &ary[i]);
			ans -= dp[i] * ary[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
