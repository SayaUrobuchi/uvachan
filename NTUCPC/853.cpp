#include <iostream>
#include <map>
using namespace std;
using mpii = map<int, int>;
using iter = mpii::iterator;

const int ADD = 1;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	mpii mp;
	mp[0] = 0;
	mp[n+1] = 0;
	for (i=0; i<m; i++)
	{
		int cmd, l, r;
		scanf("%d%d%d", &cmd, &l, &r);
		if (cmd == ADD)
		{
			int v;
			scanf("%d", &v);
			iter st = mp.lower_bound(l);
			iter ed = mp.upper_bound(r+1);
			iter it = ed;
			--it;
			int old_v = it->second;
			mp.erase(st, ed);
			mp[l] = v;
			mp[r+1] = old_v;
		}
		else
		{
			iter st = mp.lower_bound(l);
			if (st->first != l)
			{
				--st;
				mp[l] = st->second;
				++st;
			}
			iter ed = mp.lower_bound(r+1);
			if (ed->first != r+1)
			{
				--ed;
				mp[r+1] = ed->second;
				++ed;
			}
			++ed;
			iter it = st;
			int last_i = it->first;
			int last_v = it->second;
			mpii tbl;
			for (++it; it!=ed; ++it)
			{
				tbl[last_v] += it->first - last_i;
				last_i = it->first;
				last_v = it->second;
			}
			--ed;
			st->second = 0;
			++st;
			mp.erase(st, ed);
			long long ans = 0;
			for (it=tbl.begin(); it!=tbl.end(); ++it)
			{
				if (it->first)
				{
					ans += it->second * 1LL * it->second;
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
