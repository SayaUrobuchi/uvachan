#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

using pp = pair<string, string>;
using sss = unordered_set<string>;
using mm = unordered_map<string, sss>;

char buf[1024];

int main()
{
	int count, n, m, i, j, k;
	mm tbl;
	set<pp> res;
	sss v0, v1;
	vector<sss> ary, bry;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		ary.resize(n);
		bry.resize(n);
		v0.clear();
		v1.clear();
		for (i=0; i<n; i++)
		{
			scanf("%*s%d", &m);
			ary[i].clear();
			for (j=0; j<m; j++)
			{
				scanf("%s", buf);
				ary[i].insert(buf);
				v0.insert(buf);
			}
			scanf("%d", &m);
			bry[i].clear();
			for (j=0; j<m; j++)
			{
				scanf("%s", buf);
				bry[i].insert(buf);
				v1.insert(buf);
			}
		}
		res.clear();
		for (sss::iterator si=v0.begin(); si!=v0.end(); ++si)
		{
			sss tmp = v1;
			for (i=0; i<n; i++)
			{
				bool app0 = ary[i].count(*si);
				for (sss::iterator it=tmp.begin(); it!=tmp.end(); )
				{
					sss::iterator t = it++;
					bool app1 = bry[i].count(*t);
					if (app0 != app1)
					{
						tmp.erase(t);
					}
				}
			}
			for (sss::iterator it=tmp.begin(); it!=tmp.end(); ++it)
			{
				res.emplace(*si, *it);
			}
		}
		for (set<pp>::iterator it=res.begin(); it!=res.end(); ++it)
		{
			printf("(%s, %s)\n", (*it).first.c_str(), (*it).second.c_str());
		}
		if (count)
		{
			puts("");
		}
	}
	return 0;
}
