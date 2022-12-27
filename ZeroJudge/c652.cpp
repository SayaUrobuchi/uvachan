#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

const int N = 300005;

int n;
long long ary[N], bit[N];

void fix(int pos, long long val)
{
	for (; pos<=n; pos+=(pos&-pos))
	{
		bit[pos] += val;
	}
}

long long getsum(int t)
{
	long long res;
	for (res=0; t; t-=(t&-t))
	{
		res += bit[t];
	}
	return res;
}

long long query(int ql, int qr)
{
	return getsum(qr) - getsum(ql-1);
}

void build()
{
	for (int i=1; i<=n; i++)
	{
		fix(i, ary[i]);
	}
}

int main()
{
	int m, i;
	map<int, long long> mp;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%lld", &ary[i]);
		mp[i] = ary[i];
	}
	build();
	for (i=0; i<m; i++)
	{
		int cmd, a, b;
		scanf("%d%d%d", &cmd, &a, &b);
		if (cmd == 0)
		{
			printf("%lld\n", query(a, b));
		}
		else
		{
			decltype(mp)::iterator it = mp.lower_bound(a);
			vector<int> dead;
			for (; it!=mp.end()&&it->first<=b; ++it)
			{
				int nxt = sqrt(it->second)+1e-7;
				fix(it->first, nxt-it->second);
				it->second = nxt;
				if (nxt == 1)
				{
					dead.emplace_back(it->first);
				}
			}
			for (decltype(dead)::iterator it=dead.begin(); it!=dead.end(); ++it)
			{
				mp.erase(*it);
			}
		}
	}
	return 0;
}