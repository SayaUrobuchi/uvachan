#include <iostream>
#include <tuple>
#include <vector>
#include <set>
using namespace std;
using ppp = pair<int, pair<string, int> >;

const char *END_STAT = "123456780";

int main()
{
	int m, i, j, a, b, d, pos, npos, ans;
	string st;
	vector<vector<int> > edg(9);
	set<string> se;
	vector<ppp> qq;
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		--a, --b;
		edg[a].emplace_back(b);
		edg[b].emplace_back(a);
	}
	st.resize(9, '0');
	for (i=1; i<=8; i++)
	{
		scanf("%d", &a);
		st[a-1] = i + '0';
	}
	pos = st.find('0');
	se.insert(st);
	qq.emplace_back(make_pair(0, make_pair(st, pos)));
	ans = -1;
	for (i=0; i<qq.size(); i++)
	{
		forward_as_tuple(d, tie(st, pos)) = qq[i];
		if (st == END_STAT)
		{
			ans = d;
			break;
		}
		for (j=0; j<edg[pos].size(); j++)
		{
			npos = edg[pos][j];
			swap(st[pos], st[npos]);
			if (!se.count(st))
			{
				se.insert(st);
				qq.emplace_back(make_pair(d+1, make_pair(st, npos)));
			}
			swap(st[pos], st[npos]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
