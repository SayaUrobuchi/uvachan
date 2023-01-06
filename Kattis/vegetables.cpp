#include <iostream>
#include <set>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<pp, int>;

long long frac_comp(long long a, long long b, long long c, long long d)
{
	return a*d - b*c;
}

struct comp
{
	bool operator()(const ppp &a, const ppp &b) const
	{
		int res = frac_comp(a.first.first, a.first.second, b.first.first, b.first.second);
		if (res == 0)
		{
			return a.second < b.second;
		}
		return res < 0;
	}
};

bool judge(const set<ppp, comp> &se, int rat)
{
	auto ita = se.begin();
	auto itb = se.end();
	--itb;
	// (a/b) >= (c/d)*rat/100
	// => (a/b)*100 >= (c/d)*rat
	return frac_comp((ita->first).first*100, (ita->first).second, 
					 (itb->first).first*rat, (itb->first).second) >= 0;
}

int main()
{
	int n, i, t, rat, ans;
	scanf("0.%d%d", &rat, &n);
	set<ppp, comp> se;
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		se.emplace(make_pair(t, 1), i);
	}
	ans = 0;
	while (!judge(se, rat))
	{
		decltype(se)::iterator it = se.end();
		--it;
		ppp nxt = *it;
		++nxt.first.second;
		se.erase(it);
		se.insert(nxt);
		++ans;
	}
	printf("%d\n", ans);
	return 0;
}