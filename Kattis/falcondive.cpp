#include <iostream>
#include <vector>
using namespace std;

char ary[1024][1024], bry[1024][1024], board[1024][1024];
vector<pair<int, int> > pa, pb;

int main()
{
	int n, m, i, j, x, y;
	char c;
	while (scanf("%d%d '%c'", &n, &m, &c) == 3)
	{
		pa.clear();
		for (i=0; i<n; i++)
		{
			scanf("%s", ary[i]);
			board[i][m] = '\0';
		}
		pb.clear();
		for (i=0; i<n; i++)
		{
			scanf("%s", bry[i]);
			for (j=0; j<m; j++)
			{
				if (ary[i][j] == c)
				{
					pa.emplace_back(i, j);
				}
				else if (bry[i][j] == c)
				{
					pb.emplace_back(i, j);
				}
				board[i][j] = (ary[i][j] == c ? bry[i][j] : ary[i][j]);
			}
		}
		for (i=0; i<pa.size(); i++)
		{
			x = pa[i].first + ((pb[i].first-pa[i].first)<<1);
			y = pa[i].second + ((pb[i].second-pa[i].second)<<1);
			if (x >= 0 && x < n && y >= 0 && y < m)
			{
				board[x][y] = c;
			}
		}
		for (i=0; i<n; i++)
		{
			puts(board[i]);
		}
	}
	return 0;
}
