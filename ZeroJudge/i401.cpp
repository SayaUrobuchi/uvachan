#include <iostream>
#include <algorithm>
using namespace std;

const int N = 262144;
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

struct data
{
	int x, y, t;
};

int n;
data ary[N], bry[N];

bool comp(const data &a, const data &b)
{
	if (a.x != b.x)
	{
		return a.x < b.x;
	}
	return a.y < b.y;
}

int bs_up(const data ary[], int x, int y)
{
	int l, r, mid, res;
	for (l=0, r=n-1, res=n; l<=r; )
	{
		mid = ((l+r) >> 1);
		if (ary[mid].x > x || ary[mid].x == x && ary[mid].y > y)
		{
			res = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return res;
}

int main()
{
	int i, x, y, dir, ans, idx;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i].x >> ary[i].y >> ary[i].t;
			bry[i] = ary[i];
			swap(bry[i].x, bry[i].y);
		}
		sort(ary, ary+n, comp);
		sort(bry, bry+n, comp);
		for (x=0, y=0, dir=EAST, ans=0; ; ans++)
		{
			if (dir == EAST)
			{
				idx = bs_up(bry, y, x);
				if (idx >= n || bry[idx].x != y)
				{
					break;
				}
				x = bry[idx].y;
				y = bry[idx].x;
				if (bry[idx].t)
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
				idx = bs_up(bry, y, x-1) - 1;
				if (idx < 0 || bry[idx].x != y)
				{
					break;
				}
				x = bry[idx].y;
				y = bry[idx].x;
				if (bry[idx].t)
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
				idx = bs_up(ary, x, y);
				if (idx >= n || ary[idx].x != x)
				{
					break;
				}
				x = ary[idx].x;
				y = ary[idx].y;
				if (ary[idx].t)
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
				idx = bs_up(ary, x, y-1) - 1;
				if (idx < 0 || ary[idx].x != x)
				{
					break;
				}
				x = ary[idx].x;
				y = ary[idx].y;
				if (ary[idx].t)
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

