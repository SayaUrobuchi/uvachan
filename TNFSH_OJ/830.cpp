#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

const int N = 200005;

pp ary[N];

bool is_in(const pp &a, const pp &b)
{
	return b.first <= a.first && b.second >= a.second;
}

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &ary[i].first, &ary[i].second);
		if (ary[i].first > ary[i].second)
		{
			swap(ary[i].first, ary[i].second);
		}
	}
	sort(ary, ary+m);
	int ans = 0;
	vector<ppp> stk;
	stk.emplace_back(n, make_pair(1, n));
	for (i=0; i<m; i++)
	{
		while (!is_in(ary[i], stk.back().second))
		{
			ans += stk.back().first / 2;
			stk.pop_back();
		}
		int siz = (ary[i].second - ary[i].first + 1);
		stk.back().first -= siz;
		stk.emplace_back(siz-2, ary[i]);
	}
	while (stk.size())
	{
		ans += stk.back().first / 2;
		stk.pop_back();
	}
	printf("%d\n", ans);
	return 0;
}