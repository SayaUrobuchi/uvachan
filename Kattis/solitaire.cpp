#include <iostream>
#include <vector>
#include <set>
#include <tuple>
using namespace std;
using pp = pair<long long, int>;

const int R = 5;
const int C = 9;
const int RC = R * C;
const int DD[] = {1, C, -1, -C};

bool is_obstacle[RC];
char board[R][C+1];

inline int enc(int x, int y)
{
	return x*C + y;
}

inline bool movable(int t, int k, long long b)
{
	int pos = t + (DD[k] << 1);
	if (abs(pos%C - t%C) <= 2)
	{
		if (pos >= 0 && pos < RC && !is_obstacle[pos])
		{
			if (!(b & (1LL << pos)))
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int count, i, j, k;
	is_obstacle[enc(0, 0)] = is_obstacle[enc(0, 1)] = is_obstacle[enc(0, 2)] = true;
	is_obstacle[enc(0, 6)] = is_obstacle[enc(0, 7)] = is_obstacle[enc(0, 8)] = true;
	is_obstacle[enc(4, 0)] = is_obstacle[enc(4, 1)] = is_obstacle[enc(4, 2)] = true;
	is_obstacle[enc(4, 6)] = is_obstacle[enc(4, 7)] = is_obstacle[enc(4, 8)] = true;
	scanf("%d", &count);
	while (count--)
	{
		long long st = 0;
		int c = 0;
		for (i=0; i<R; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<C; j++)
			{
				if (board[i][j] == 'o')
				{
					st |= 1LL << enc(i, j);
					++c;
				}
			}
		}
		int ans = 0;
		vector<pp> que;
		set<long long> se;
		que.emplace_back(st, 0);
		se.insert(st);
		for (i=0; i<que.size(); i++)
		{
			long long cur;
			int d;
			tie(cur, d) = que[i];
			ans = d;
			for (j=0; j<RC; j++)
			{
				if (cur & (1LL << j))
				{
					for (k=0; k<4; k++)
					{
						if (movable(j, k, cur) && (cur & (1LL << (j+DD[k]))))
						{
							long long nxt = cur | (1LL << (j+(DD[k]<<1)));
							nxt ^= (1LL << j) | (1LL << (j+DD[k]));
							if (!se.count(nxt))
							{
								que.emplace_back(nxt, d+1);
								se.insert(nxt);
							}
						}
					}
				}
			}
		}
		printf("%d %d\n", c-ans, ans);
	}
	return 0;
}
