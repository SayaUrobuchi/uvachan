#include <stdio.h>

#define M 5000

int tbl[10], dp[M+8];

int main()
{
	int i, j, n, m;
	for (i=1; i<=M; i++)
	{
		dp[i] = dp[i-1];
		for (j=i; j>0; j/=10)
		{
			if (tbl[j%10] == i)
			{
				break;
			}
			tbl[j%10] = i;
		}
		if (!j)
		{
			dp[i]++;
		}
	}
	while (scanf("%d%d", &n, &m) == 2)
	{
		printf("%d\n", dp[m]-dp[n-1]);
	}
	return 0;
}
