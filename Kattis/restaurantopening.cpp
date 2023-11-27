#include <iostream>
using namespace std;

const int N = 55;

int ary[N][N], pre[N][N], prr[N];

int main()
{
	int n, m, i, j, d, ans, cost;
	scanf("%d%d", &n, &m);
	for (i=1, cost=0; i<=n; i++)
	{
		for (j=1; j<=m; j++)
		{
			scanf("%d", &ary[i][j]);
			cost += ary[i][j] * (i - 1);
			pre[i][j] = pre[i-1][j] + ary[i][j];
		}
	}
	for (i=1, ans=2e9; i<=n; i++)
	{
		for (j=1, d=0; j<=m; j++)
		{
			prr[j] = prr[j-1] + pre[n][j];
			d += pre[n][j] * (j - 1);
		}
		for (j=1; j<=m; j++)
		{
			int c = cost + d;
			ans = min(ans, c);
			d += prr[j] - (prr[m] - prr[j]);
		}
		for (j=1; j<=m; j++)
		{
			cost += pre[i][j] - (pre[n][j] - pre[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
