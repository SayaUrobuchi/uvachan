#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

pair<int, int> ary[262144];

void adj(set<int> &se, set<int> &add, set<int> &del)
{
	for (auto it=add.begin(); it!=add.end(); ++it)
	{
		se.emplace(*it);
	}
	for (auto it=del.begin(); it!=del.end(); ++it)
	{
		se.erase(*it);
	}
	add.clear();
	del.clear();
}

int main()
{
	int n, m, i, last;
	while (scanf("%d%d", &m, &n) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i].first, &ary[i].second);
		}
		sort(ary, ary+n);
		set<int> se, add, del;
		se.insert(m);
		for (i=0, last=0; i<n; i++)
		{
			if (ary[i].first)
			{
				if (ary[i].first != last)
				{
					adj(se, add, del);
					last = ary[i].first;
				}
				if (se.count(ary[i].second-1) || se.count(ary[i].second+1))
				{
					add.emplace(ary[i].second);
				}
				else
				{
					del.emplace(ary[i].second);
				}
			}
		}
		adj(se, add, del);
		printf("%u\n", se.size());
	}
	return 0;
}

