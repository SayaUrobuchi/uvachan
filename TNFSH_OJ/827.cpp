#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2505;

int preb[N], pret[N];
char board[N][N];

int main()
{
	int n, m, i, j, k, l;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	int ans = m + 1;
	for (k=0; k<2; k++)
	{
		for (i=-(n-1); i<n; i++)
		{
			int x = (i < 0 ? -i : 0);
			int y = max(0, i);
			if (x + m <= n && y + m <= n)
			{
				for (j=1; x<n&&y<n; j++, x++, y++)
				{
					preb[j] = preb[j-1] + (board[x][y] == 'B');
					pret[j] = pret[j-1] + (board[x][y] == 'T' || board[x][y] == '#');
				}
				for (l=m; l<j; l++)
				{
					if (pret[l] - pret[l-m] == 0)
					{
						int res = m - (preb[l] - preb[l-m]);
						ans = min(ans, res);
					}
				}
			}
		}
		for (i=0; i<n; i++)
		{
			reverse(board[i], board[i]+n);
		}
	}
	if (ans > m)
	{
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}