#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<pp, int>;

const int N = 262144;

ppp ary[N];
int bry[N];

int main()
{
	int n, m, i, last, st, ed, len;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &ary[i].first.second, &ary[i].first.first, &ary[i].second);
		}
		sort(ary, ary+m);
		vector<int> v;
		for (i=0; i<=n; i++)
		{
			bry[i] = 0;
		}
		for (i=0, last=1; i<m; i++)
		{
			st = ary[i].first.second;
			ed = ary[i].first.first;
			len = ary[i].second;
			for (; last<=ed; last++)
			{
				v.emplace_back(last);
			}
			auto it = lower_bound(v.begin(), v.end(), st);
			len -= (ed-st+1) - (v.end() - it);
			while (len > 0)
			{
				--len;
				bry[v.back()] = 1;
				v.pop_back();
			}
		}
		printf("%d", bry[1]);
		for (i=2; i<=n; i++)
		{
			printf(" %d", bry[i]);
		}
		puts("");
	}
	return 0;
}

