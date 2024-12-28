#include <iostream>
using namespace std;

const int N = 105;

int ary[N][N][N];

int main()
{
	int n, m, i, j, k;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
		{
			for (k=1; k<=n; k++)
			{
				scanf("%d", &ary[i][j][k]);
				ary[i][j][k] += ary[i-1][j][k] + ary[i][j-1][k] + ary[i][j][k-1];
				ary[i][j][k] -= ary[i-1][j-1][k] + ary[i-1][j][k-1] + ary[i][j-1][k-1];
				ary[i][j][k] += ary[i-1][j-1][k-1];
			}
		}
	}
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		int a, b, c, d, e, f;
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		int ans = ary[b][d][f];
		ans -= ary[a-1][d][f] + ary[b][c-1][f] + ary[b][d][e-1];
		ans += ary[a-1][c-1][f] + ary[b][c-1][e-1] + ary[a-1][d][e-1];
		ans -= ary[a-1][c-1][e-1];
		printf("%d\n", ans);
	}
	return 0;
}
