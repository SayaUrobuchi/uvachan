#include <iostream>
using namespace std;

const int N = 2005;
const int M = 2005;

int dp[N][M], from[N][M];

void trace(int i, int j, int c)
{
	if (i == 0)
	{
		printf("%d\n", c);
		return;
	}
	trace(i-1, from[i][j], c+(from[i][j]!=j));
	if (from[i][j] != j)
	{
		printf("%d%c", i-1, (c==0)[" \n"]);
	}
}

int main()
{
	int n, m, i, j;
	while (scanf("%d%d", &m, &n) == 2)
	{
		for (i=1; i<=n; i++)
		{
			int v, w;
			scanf("%d%d", &v, &w);
			for (j=0; j<=m; j++)
			{
				dp[i][j] = dp[i-1][j];
				from[i][j] = j;
				if (j >= w && dp[i-1][j-w] + v > dp[i][j])
				{
					dp[i][j] = dp[i-1][j-w] + v;
					from[i][j] = j - w;
				}
			}
		}
		trace(n, m, 0);
	}
	return 0;
}
