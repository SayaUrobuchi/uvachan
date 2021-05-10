#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
using um = unordered_map<string, int>;

char s[32];
bool dirty[1048576];
vector<int> v[1048576];

int main()
{
	int n, m, i, t, id;
	um tbl;
	while (scanf("%d", &n) == 1)
	{
		tbl.clear();
		for (i=0; i<n; i++)
		{
			scanf("%s%d", s, &t);
			um::iterator it = tbl.find(s);
			if (it == tbl.end())
			{
				id = tbl.size();
				tbl[s] = id;
				v[id].clear();
				dirty[id] = true;
			}
			else
			{
				id = it->second;
			}
			v[id].emplace_back(t);
		}
		scanf("%d", &m);
		for (i=0; i<m; i++)
		{
			scanf("%s%d", s, &t);
			id = tbl[s];
			if (dirty[id])
			{
				dirty[id] = false;
				sort(v[id].begin(), v[id].end());
			}
			printf("%d\n", v[id][t-1]);
		}
	}
	return 0;
}
