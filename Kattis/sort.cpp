#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

using mm = unordered_map<int, int>;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

int main()
{
	int n, m, i, t;
	bool first;
	mm cnt, pos;
	vector<ppp> v;
	while (scanf("%d%d", &n, &m) == 2)
	{
		cnt.clear();
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			if (++cnt[t] == 1)
			{
				pos[t] = i;
			}
		}
		v.clear();
		for (mm::iterator it=cnt.begin(); it!=cnt.end(); ++it)
		{
			v.push_back({it->second, {-pos[it->first], it->first}});
		}
		sort(v.begin(), v.end(), greater<ppp>());
		for (i=0, first=true; i<v.size(); i++)
		{
			while (v[i].first--)
			{
				if (!first)
				{
					putchar(' ');
				}
				first = false;
				printf("%d", v[i].second.second);
			}
		}
		puts("");
	}
	return 0;
}
