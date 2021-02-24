#include <iostream>

const int LOSE = 0;
const int WIN = 1;

int ary[16], dp[1048576];

int main()
{
	int n, m, i, j;
	while (scanf("%d%d", &m, &n) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		dp[0] = LOSE;
		for (i=1; i<=m; i++)
		{
			dp[i] = LOSE;
			for (j=0; j<n; j++)
			{
				if (ary[j] <= i && dp[i-ary[j]] == LOSE)
				{
					dp[i] = WIN;
					break;
				}
			}
		}
		if (dp[m] == WIN)
		{
			puts("Stan wins");
		}
		else
		{
			puts("Ollie wins");
		}
	}
	return 0;
}
