#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int NONE = -1;
const int N = 64;

int board[N][N];

int main()
{
	int n, m, i, j, k, l, x, y, best;
	vector<int> v, tbl;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			scanf("%d", &board[i][j]);
			if (board[i][j] != NONE)
			{
				v.emplace_back(board[i][j]);
			}
		}
	}
	sort(v.begin(), v.end());
	tbl.resize(v.size());
	for (l=0, best=n*m; l<2; l++)
	{
		for (k=0; k<2; k++)
		{
			for (i=0, j=0; i<n+m; i++)
			{
				for (x=0, y=i; x<n; x++, y--)
				{
					if (x >= 0 && x < n && y >= 0 && y < m)
					{
						if (board[x][y] != NONE)
						{
							tbl[j++] = i;
						}
					}
				}
			}
			int cnt = 0;
			for (i=0, cnt=0; i<n+m; i++)
			{
				for (x=0, y=i; x<n; x++, y--)
				{
					if (x >= 0 && x < n && y >= 0 && y < m)
					{
						if (board[x][y] != NONE)
						{
							int pos = distance(v.begin(), lower_bound(v.begin(), v.end(), board[x][y]));
							if (tbl[pos] != i)
							{
								++cnt;
							}
						}
					}
				}
			}
			best = min(cnt, best);
			for (y=0; y<m; y++)
			{
				for (i=0, j=n-1; i<j; i++, j--)
				{
					swap(board[i][y], board[j][y]);
				}
			}
		}
		for (x=0; x<n; x++)
		{
			reverse(board[x], board[x]+m);
		}
	}
	printf("%d\n", best);
	return 0;
}
