#include <iostream>
#include <unordered_map>
using namespace std;

int board[16][16384];
int ary[256][16384];
int rev[256];

int main()
{
	int n, m, i, j, k, t, u, ans;
	unordered_map<int, int> tbl;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			rev[1<<i] = i;
			for (j=0; j<m; j++)
			{
				scanf("%d", &board[i][j]);
			}
		}
		for (j=0; j<m; j++)
		{
			for (i=1; i<(1<<n); i++)
			{
				u = (i&-i);
				if (u == i)
				{
					t = board[rev[u]][j];
				}
				else
				{
					if (board[rev[u]][j] == ary[i-u][j])
					{
						t = ary[i-u][j];
					}
					else
					{
						t = -1;
					}
				}
				ary[i][j] = t;
			}
		}
		ans = 1;
		for (i=1; i<(1<<n); i++)
		{
			tbl.clear();
			for (j=0, t=0; j<m; j++)
			{
				if (ary[i][j] > 0)
				{
					t = max(t, ++tbl[ary[i][j]]);
				}
			}
			for (j=i, k=0; j; k++, j&=~(j&-j));
			ans = max(ans, t*k);
		}
		printf("%d\n", ans);
	}
	return 0;
}
