#include <iostream>
using namespace std;

const int N = 128;

int ary[N][N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	int tar = 2e9;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			scanf("%d", &ary[i][j]);
			tar = min(tar, ary[i][j]);
		}
	}
	int ans = 0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			ans += ary[i][j] - tar;
		}
	}
	printf("%d\n", ans);
	return 0;
}
