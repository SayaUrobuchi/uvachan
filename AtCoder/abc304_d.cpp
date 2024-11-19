#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int N = 200005;

int bry[N];
pp ary[N];
vector<int> v[N];

int main()
{
	int w, h, n, m, o, i, j;
	scanf("%d%d", &w, &h);
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i].first, &ary[i].second);
	}
	sort(ary, ary+n);
	scanf("%d", &m);
	int cur = 0;
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		for (; cur<n&&ary[cur].first<t; ++cur)
		{
			v[i].emplace_back(ary[cur].second);
		}
	}
	for (; cur<n; ++cur)
	{
		v[i].emplace_back(ary[cur].second);
	}
	scanf("%d", &o);
	for (i=0; i<o; i++)
	{
		scanf("%d", &bry[i]);
	}
	int large = 0;
	int small = 1e9;
	for (i=0; i<=m; i++)
	{
		int last = 0;
		int cnt = 0;
		sort(v[i].begin(), v[i].end());
		for (j=0; j<v[i].size(); j++)
		{
			int t = v[i][j];
			int idx = upper_bound(bry+last, bry+o, t) - bry;
			if (idx != last)
			{
				small = min(small, cnt);
				if (idx != last+1)
				{
					small = 0;
				}
				last = idx;
				cnt = 0;
			}
			++cnt;
			large = max(large, cnt);
		}
		if (last != o)
		{
			small = 0;
		}
		small = min(small, cnt);
	}
	printf("%d %d\n", small, large);
	return 0;
}
