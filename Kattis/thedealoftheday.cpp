#include <iostream>

int ary[16];
__int128 dp[16][16];

void print(__int128 t)
{
	if (t < 10)
	{
		putchar('0'+(int)t);
		return;
	}
	print(t/10);
	printf("%d", (int)(t%10));
}

int main()
{
	int i, j, m, t;
	while (scanf("%d", &ary[1]) == 1)
	{
		dp[1][1] = ary[1];
		for (i=2; i<=10; i++)
		{
			scanf("%d", &ary[i]);
			dp[1][i] = dp[1][i-1] + ary[i];
		}
		scanf("%d", &m);
		for (i=2; i<=m; i++)
		{
			for (j=1; j<=10; j++)
			{
				dp[i][j] = dp[i-1][j-1]*ary[j] + dp[i][j-1];
			}
		}
		print(dp[m][10]);
		puts("");
	}
	return 0;
}
