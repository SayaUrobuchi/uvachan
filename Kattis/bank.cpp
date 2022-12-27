#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> ary[16384];

int main()
{
	int n, m, i, ans;
	vector<int> v;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i].second, &ary[i].first);
			++ary[i].first;
		}
		sort(ary, ary+n);
		v.clear();
		for (i=0; i<n; i++)
		{
			auto it = lower_bound(v.begin(), v.end(), ary[i].second, greater<int>());
			v.insert(it, ary[i].second);
			if (v.size() > ary[i].first)
			{
				v.resize(ary[i].first);
			}
		}
		for (i=0, ans=0; i<v.size(); i++)
		{
			ans += v[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}

