#include <iostream>
#include <map>
#include <vector>
using namespace std;
using pp = pair<string, int>;

int main()
{
	int m, sn;
	scanf("%d", &m);
	sn = 0;
	map<pp, string> mp;
	vector<bool> avail;
	vector<int> level;
	bool gg = false;
	int cur_lv = 0;
	level.emplace_back(cur_lv++);
	avail.emplace_back(true);
	for (int i=0; i<m; i++)
	{
		char cmd[32], typ[32], var[32];
		scanf("%s", cmd);
		if (*cmd == '{')
		{
			++sn;
			if (level.size() < sn+1)
			{
				level.resize(sn+1);
			}
			level[sn] = cur_lv++;
			avail.emplace_back(true);
		}
		else if (*cmd == '}')
		{
			avail[level[sn]] = false;
			--sn;
		}
		else if (*cmd == 'D')
		{
			scanf("%s%s", var, typ);
			if (mp.find(make_pair(var, level[sn])) == mp.end())
			{
				mp[make_pair(var, level[sn])] = typ;
			}
			else
			{
				gg = true;
				break;
			}
		}
		else
		{
			scanf("%s", var);
			bool found = false;
			if (!mp.empty())
			{
				auto it = mp.lower_bound(make_pair(var, cur_lv));
				if (it != mp.begin())
				{
					--it;
					while ((it->first).first == var)
					{
						if (avail[(it->first).second])
						{
							puts((it->second).c_str());
							found = true;
							break;
						}
						auto temp = it;
						if (it != mp.begin())
						{
							--it;
						}
						else
						{
							break;
						}
						mp.erase(temp);
					}
				}
			}
			if (!found)
			{
				puts("UNDECLARED");
			}
		}
	}
	if (gg)
	{
		puts("MULTIPLE DECLARATION");
	}
	return 0;
}