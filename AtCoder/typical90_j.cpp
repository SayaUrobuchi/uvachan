#include <iostream>
using namespace std;

int sum[4][131072];

int main()
{
	int n, m, i, j, t, u;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d%d", &t, &u);
			for (j=1; j<=2; j++)
			{
				if (j == t)
				{
					sum[j][i] = sum[j][i-1] + u;
				}
				else
				{
					sum[j][i] = sum[j][i-1];
				}
			}
		}
		scanf("%d", &m);
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &t, &u);
			printf("%d %d\n", sum[1][u]-sum[1][t-1], sum[2][u]-sum[2][t-1]);
		}
	}
	return 0;
}
