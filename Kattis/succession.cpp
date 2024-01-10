#include <iostream>
#include <map>
using namespace std;
using pp = pair<int, int>;

const int N = 256;
const int SLEN = 16;

int cc;
char buf[SLEN], buf2[SLEN], buf3[SLEN];
map<string, int> mp;
double dp[N];
bool used[N];
pp par[N];

inline int get_id(const string &s)
{
	decltype(mp)::iterator it = mp.find(s);
	if (it == mp.end())
	{
		it = mp.insert(make_pair(s, cc++)).first;
	}
	return it->second;
}

double calc(int id)
{
	if (used[id])
	{
		return dp[id];
	}
	used[id] = true;
	if (id == 1)
	{
		return dp[id] = 1;
	}
	if (par[id].first)
	{
		return dp[id] = (calc(par[id].first) + calc(par[id].second)) / 2;
	}
	return dp[id] = 0;
}

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	scanf("%s", buf);
	cc = 1;
	mp[buf] = cc++;
	for (i=0; i<n; i++)
	{
		scanf("%s%s%s", buf, buf2, buf3);
		int id = get_id(buf);
		par[id] = make_pair(get_id(buf2), get_id(buf3));
	}
	double best = 0;
	string best_nam;
	for (i=0; i<m; i++)
	{
		scanf("%s", buf);
		int id = get_id(buf);
		double blood = calc(id);
		if (blood > best)
		{
			best = blood;
			best_nam = buf;
		}
	}
	puts(best_nam.c_str());
	return 0;
}
