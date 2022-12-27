#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using ull = unsigned long long;
using pp = pair<ull, int>;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

char board[16][16];

inline ull bi(int i, int j)
{
	return 1LL << ((i<<3)|j);
}

int main()
{
	int n, m, i, j, k, ans, x, y, nx, ny;
	ull stat, cur, ns;
	vector<pp> que;
	unordered_set<ull> used;
	while (scanf("%d%d", &n, &m) == 2)
	{
		que.clear();
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<n; j++)
			{
				if (board[i][j] == '.')
				{
					que.emplace_back(bi(i, j), 1);
				}
			}
		}
		used.clear();
		for (i=0, ans=0; i<que.size(); i++)
		{
			if (que[i].second == m)
			{
				++ans;
				continue;
			}
			stat = cur = que[i].first;
			for (j=0; stat; j++, stat>>=1)
			{
				if (stat & 1)
				{
					x = (j >> 3);
					y = (j & 7);
					for (k=0; k<4; k++)
					{
						nx = x + dx[k];
						ny = y + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < n)
						{
							if (board[nx][ny] == '.')
							{
								ns = (cur | bi(nx, ny));
								if (!used.count(ns))
								{
									used.insert(ns);
									que.emplace_back(ns, que[i].second+1);
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

