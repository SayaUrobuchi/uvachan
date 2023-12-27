#include <iostream>
#include <map>
using namespace std;

const int LEFT = 0;
const int RIGHT = 1;
const int ANY = 2;

int tbl[128];
char buf[2][128];

struct dat
{
	int v[3];
};

int main()
{
	int n, i;
	tbl['l'] = LEFT;
	tbl['r'] = RIGHT;
	tbl['a'] = ANY;
	scanf("%d", &n);
	map<string, dat> mp;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%s%s%d", buf[0], buf[1], &t);
		mp[buf[0]].v[tbl[*buf[1]]] = t;
	}
	bool fitable = false;
	int ans = 0;
	for (decltype(mp)::iterator it=mp.begin(); it!=mp.end(); ++it)
	{
		dat &cur = it->second;
		if ((cur.v[LEFT] && cur.v[RIGHT]) || cur.v[ANY] >= 2)
		{
			fitable = true;
		}
		if (cur.v[LEFT] || cur.v[RIGHT])
		{
			ans += max(cur.v[LEFT], cur.v[RIGHT]);
		}
		else
		{
			ans += min(1, cur.v[ANY]);
		}
	}
	if (fitable)
	{
		printf("%d\n", ans+1);
	}
	else
	{
		puts("impossible");
	}
	return 0;
}
