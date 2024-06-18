#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int N = 200005;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const char *key = "URDL";

int tbl[128];
pp ary[N];
bool avail[N];
char cmd[N];

int main()
{
	int n, m, hp, heal, i;
	for (i=0; i<4; i++)
	{
		tbl[key[i]] = i;
	}
	scanf("%d%d%d%d", &n, &m, &hp, &heal);
	scanf("%s", cmd);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &ary[i].first, &ary[i].second);
		avail[i] = true;
	}
	sort(ary, ary+m);
	int x = 0;
	int y = 0;
	bool alive = true;
	for (i=0; i<n; i++)
	{
		--hp;
		if (hp < 0)
		{
			alive = false;
			break;
		}
		x += DX[tbl[cmd[i]]];
		y += DY[tbl[cmd[i]]];
		pp t = make_pair(x, y);
		int idx = lower_bound(ary, ary+m, t) - ary;
		if (idx < m && ary[idx] == t && avail[idx] && hp < heal)
		{
			avail[idx] = false;
			hp = heal;
		}
	}
	puts(alive ? "Yes" : "No");
	return 0;
}
