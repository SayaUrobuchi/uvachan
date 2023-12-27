#include <iostream>
using namespace std;

const int N = 505;

int pre[N][N];

int main()
{
	int n, i, j, a, b, c, d;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0; i<N; i++)
		{
			for (j=0; j<N; j++)
			{
				pre[i][j] = 0;
			}
		}
		for (i=0; i<n; i++)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			++pre[a][b];
			--pre[a][d];
			--pre[c][b];
			++pre[c][d];
		}
		for (i=0; i<N; i++)
		{
			for (j=1; j<N; j++)
			{
				pre[i][j] += pre[i][j-1];
			}
		}
		for (i=1; i<N; i++)
		{
			for (j=0; j<N; j++)
			{
				pre[i][j] += pre[i-1][j];
			}
		}
		int ans = 0;
		for (i=0; i<N; i++)
		{
			for (j=0; j<N; j++)
			{
				ans += (pre[i][j] > 0);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
