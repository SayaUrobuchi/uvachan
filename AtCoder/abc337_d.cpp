#include <iostream>
#include <vector>
using namespace std;

const int N = 200005;

char buf[N];

int main()
{
	int n, m, k, i, j, l, r, x, o;
	scanf("%d%d%d", &n, &m, &k);
	int ans = k + 1;
	bool ok = false;
	vector<string> board;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		board.emplace_back(buf);
		for (r=0, l=r-k+1, x=0, o=0; r<m; r++, l++)
		{
			if (board[i][r] == '.')
			{
				++o;
			}
			else if (board[i][r] == 'x')
			{
				++x;
			}
			if (x == 0 && l >= 0)
			{
				ok = true;
				ans = min(ans, o);
			}
			if (l >= 0)
			{
				if (board[i][l] == '.')
				{
					--o;
				}
				else if (board[i][l] == 'x')
				{
					--x;
				}
			}
		}
	}
	for (j=0; j<m; j++)
	{
		for (r=0, l=r-k+1, x=0, o=0; r<n; r++, l++)
		{
			if (board[r][j] == '.')
			{
				++o;
			}
			else if (board[r][j] == 'x')
			{
				++x;
			}
			if (x == 0 && l >= 0)
			{
				ok = true;
				ans = min(ans, o);
			}
			if (l >= 0)
			{
				if (board[l][j] == '.')
				{
					--o;
				}
				else if (board[l][j] == 'x')
				{
					--x;
				}
			}
		}
	}
	if (!ok)
	{
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}
