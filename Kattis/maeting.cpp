#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<string, int>;

const int N = 105;

pp ary[N];
char buf[32];

bool comp(const pp &a, const pp &b)
{
	return a.second > b.second;
}

int main()
{
	int n, m, i, j, t;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		string tmp = buf;
		ary[i] = make_pair(tmp, 0);
	}
	sort(ary, ary+n);
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		scanf("%d", &t);
		for (j=0; j<t; j++)
		{
			scanf("%s", buf);
			string tmp = buf;
			++(lower_bound(ary, ary+n, make_pair(tmp, 0))->second);
		}
	}
	sort(ary, ary+n, comp);
	for (i=0; i<n; i++)
	{
		printf("%d %s\n", ary[i].second, ary[i].first.c_str());
	}
	return 0;
}
