#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> ary[262144];

int main()
{
	int n, m, i, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i].first, &ary[i].second);
		}
		sort(ary, ary+n);
		set<pair<int, int> > se;
		for (i=0, ans=0; i<n; i++)
		{
			if (se.size() < m)
			{
				se.insert({ary[i].second, i});
				++ans;
			}
			else if ((se.begin())->first <= ary[i].first)
			{
				se.erase(se.begin());
				se.insert({ary[i].second, i});
				++ans;
			}
			else
			{
				auto it = se.end();
				--it;
				if (it->first > ary[i].second)
				{
					se.erase(it);
					se.insert({ary[i].second, i});
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

