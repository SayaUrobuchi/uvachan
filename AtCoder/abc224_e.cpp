#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
using p2p = pair<int, int>;
using p4p = pair<p2p, p2p>;

const int N = 200005;

int ans[N], row[N], col[N];
p4p ary[N];

int main()
{
	int n, m, o, i, j;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<o; i++)
	{
		scanf("%d%d%d", &ary[i].second.first, &ary[i].second.second, &ary[i].first.first);
		ary[i].first.second = i;
	}
	sort(ary, ary+o, greater<p4p>());
	for (i=0; i<o; i=j)
	{
		int a, id, x, y;
		for (j=i; j<o&&ary[i].first.first==ary[j].first.first; j++)
		{
			forward_as_tuple(tie(a, id), tie(x, y)) = ary[j];
			ans[id] = max(row[x], col[y]);
		}
		for (j=i; j<o&&ary[i].first.first==ary[j].first.first; j++)
		{
			forward_as_tuple(tie(a, id), tie(x, y)) = ary[j];
			row[x] = max(row[x], ans[id]+1);
			col[y] = max(col[y], ans[id]+1);
		}
	}
	for (i=0; i<o; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
