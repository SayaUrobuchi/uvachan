#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, pair<int, int> >;

int cur[1024];
pp ary[1024];

int main()
{
	int n, m, t, i, j, now, id, day, val;
	bool first;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, m=0; i<n; i++)
		{
			cur[i] = 0;
			scanf("%d", &t);
			for (j=0; j<t; j++, m++)
			{
				scanf("%d%d", &ary[m].second.second, &ary[m].first);
				ary[m].second.first = i;
			}
		}
		sort(ary, ary+m);
		for (i=0, now=0, first=true; i<m; i++)
		{
			day = ary[i].first;
			id = ary[i].second.first;
			val = ary[i].second.second;
			now += val - cur[id];
			cur[id] = val;
			if (i+1 >= m || ary[i+1].first != day)
			{
				if (!first)
				{
					putchar(' ');
				}
				first = false;
				printf("%d", now);
			}
		}
		puts("");
	}
	return 0;
}
