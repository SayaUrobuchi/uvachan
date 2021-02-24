#include <iostream>

const int T = 8;
const int N = 256;

int dp[T][N], from[T][N];

int main()
{
	int n, i, j, k, l, t;
	dp[0][0] = 1;
	for (i=1; i<=3; i++)
	{
		for (j=0; j<=180; j++)
		{
			dp[i][j] = dp[i-1][j];
			from[i][j] = 0;
			for (k=1; k<=20&&k<=j&&!dp[i][j]; k++)
			{
				for (l=1; l<=3&&k*l<=j&&!dp[i][j]; l++)
				{
					if (dp[i-1][j-k*l])
					{
						dp[i][j] = 1;
						from[i][j] = k*l;
					}
				}
			}
		}
	}
	while (scanf("%d", &n) == 1)
	{
		if (dp[3][n])
		{
			for (i=3; i>0; i--)
			{
				t = from[i][n];
				n -= t;
				if (t)
				{
					if (t % 3 == 0)
					{
						printf("triple %d\n", t/3);
					}
					else if ((t & 1) == 0)
					{
						printf("double %d\n", t>>1);
					}
					else
					{
						printf("single %d\n", t);
					}
				}
			}
		}
		else
		{
			puts("impossible");
		}
	}
	return 0;
}
