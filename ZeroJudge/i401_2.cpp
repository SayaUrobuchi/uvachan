#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 262144;
const int M = 60001;
const int FIX = 30000;
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

vector<pair<int, int> > px[M], py[M];

int main()
{
	int n, i, x, y, dir, ans, idx;
	while (cin >> n)
	{
		for (i=0; i<M; i++)
		{
			px[i].clear();
			py[i].clear();
		}
		for (i=0; i<n; i++)
		{
			cin >> x >> y >> dir;
			px[x+FIX].emplace_back(y+FIX, dir);
			py[y+FIX].emplace_back(x+FIX, dir);
		}
		for (i=0; i<M; i++)
		{
			sort(px[i].begin(), px[i].end());
			sort(py[i].begin(), py[i].end());
		}
		for (x=0+FIX, y=0+FIX, dir=EAST, ans=0; ; ans++)
		{
			if (dir == EAST)
			{
				auto it = upper_bound(py[y].begin(), py[y].end(), make_pair(x, 1));
				if (it == py[y].end())
				{
					break;
				}
				x = it->first;
				if (it->second)
				{
					dir = SOUTH;
				}
				else
				{
					dir = NORTH;
				}
			}
			else if (dir == WEST)
			{
				auto it = lower_bound(py[y].begin(), py[y].end(), make_pair(x, 0));
				if (it == py[y].begin())
				{
					break;
				}
				--it;
				x = it->first;
				if (it->second)
				{
					dir = NORTH;
				}
				else
				{
					dir = SOUTH;
				}
			}
			else if (dir == NORTH)
			{
				auto it = upper_bound(px[x].begin(), px[x].end(), make_pair(y, 1));
				if (it == px[x].end())
				{
					break;
				}
				y = it->first;
				if (it->second)
				{
					dir = WEST;
				}
				else
				{
					dir = EAST;
				}
			}
			else
			{
				auto it = lower_bound(px[x].begin(), px[x].end(), make_pair(y, 0));
				if (it == px[x].begin())
				{
					break;
				}
				--it;
				y = it->first;
				if (it->second)
				{
					dir = EAST;
				}
				else
				{
					dir = WEST;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

