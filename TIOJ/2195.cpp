#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pp = pair<int, int>;

int main()
{
	int n, i;
	scanf("%d", &n);
	vector<pp> u;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		u.emplace_back(t, i);
	}
	sort(u.begin(), u.end());
	vector<int> v(n);
	vector<int> id(n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &id[i]);
		v[i] = lower_bound(u.begin(), u.end(), make_pair(id[i], 0))->second;
	}
	vector<vector<pp> > lis;
	for (i=n-1; i>=0; i--)
	{
		int cur = v[i];
		int l = 0;
		int r = lis.size() - 1;
		int ans = 0;
		while (l <= r)
		{
			int mid = ((l + r) >> 1);
			if (cur < lis[mid].back().first)
			{
				ans = mid + 1;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		if (ans == lis.size())
		{
			lis.resize(ans+1);
		}
		lis[ans].emplace_back(cur, i);
	}
	bool first = true;
	int lastf = -1;
	int lasts = -1;
	for (auto it=lis.rbegin(); it!=lis.rend(); ++it)
	{
		int mx = -1;
		int f, s;
		for (auto iu = it->begin(); iu!=it->end()&&iu->second>lasts; ++iu)
		{
			int val = id[iu->second];
			if (val > mx && iu->first > lastf)
			{
				mx = val;
				f = iu->first;
				s = iu->second;
			}
		}
		if (!first)
		{
			putchar(' ');
		}
		first = false;
		printf("%d", mx);
		lastf = f;
		lasts = s;
	}
	puts("");
	return 0;
}
