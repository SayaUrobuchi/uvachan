#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
using pp = pair<int, string>;

int main()
{
	int n, i, id;
	string s;
	unordered_set<string> se[16384], ans;
	unordered_map<string, int> tbl, nam;
	vector<pp> final;
	while (scanf("%d", &n) == 1)
	{
		getline(cin, s);
		ans.clear();
		nam.clear();
		for (i=0; i<n; i++)
		{
			getline(cin, s);
			stringstream ss(s);
			ss >> s;
			unordered_map<string, int>::iterator it=nam.find(s);
			if (it == nam.end())
			{
				id = nam.size();
				nam[s] = id;
				se[id].clear();
			}
			else
			{
				id = it->second;
			}
			while (ss >> s)
			{
				se[id].insert(s);
				++tbl[s];
			}
		}
		ans = se[0];
		for (i=1; i<nam.size(); i++)
		{
			for (unordered_set<string>::iterator it=ans.begin(); it!=ans.end(); )
			{
				if (!se[i].count(*it))
				{
					unordered_set<string>::iterator temp = it;
					++it;
					ans.erase(temp);
				}
				else
				{
					++it;
				}
			}
		}
		if (ans.size())
		{
			final.clear();
			for (unordered_set<string>::iterator it=ans.begin(); it!=ans.end(); ++it)
			{
				final.emplace_back(-tbl[*it], *it);
			}
			sort(final.begin(), final.end());
			for (i=0; i<final.size(); i++)
			{
				puts(final[i].second.c_str());
			}
		}
		else
		{
			puts("ALL CLEAR");
		}
	}
	return 0;
}