#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<pp, int>;

char cmd[32];

int main()
{
	int n, m, o, i, t;
	priority_queue<pp> avail;
	priority_queue<int> dead;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		avail.emplace(t, t);
	}
	scanf("%d", &o);
	int zn = 0;
	int rn = 0;
	bool gameover = false;
	vector<ppp> rest;
	vector<int> zombie;
	for (i=1; i<=o&&!gameover; i++)
	{
		// medicine
		if (i % m == 0)
		{
			if (!dead.empty())
			{
				int max_hp = dead.top();
				if (max_hp > 1)
				{
					dead.pop();
					avail.emplace(max_hp>>1, max_hp);
				}
			}
		}
		// recover
		for (; rn<rest.size()&&rest[rn].second<=i; ++rn)
		{
			avail.emplace(rest[rn].first);
		}
		// event
		scanf("%s", cmd);
		if (cmd[1] == 'P')
		{
			int t;
			scanf("%d", &t);
			zombie.emplace_back(t);
		}
		else
		{
			int cur = zombie[zn];
			++zn;
			while (cur > 0)
			{
				if (avail.empty())
				{
					gameover = true;
					break;
				}
				pp fighter = avail.top();
				avail.pop();
				int dmg = min(cur, fighter.first);
				cur -= dmg;
				fighter.first -= dmg;
				if (fighter.first == 0)
				{
					dead.emplace(fighter.second);
				}
				else
				{
					rest.emplace_back(fighter, i+2);
				}
			}
		}
	}
	puts(gameover ? "overrun" : "success");
	return 0;
}