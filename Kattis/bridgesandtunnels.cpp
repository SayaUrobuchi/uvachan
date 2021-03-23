#include <iostream>
#include <unordered_map>
using namespace std;
using mm = unordered_map<string, int>;

int par[1048576], cnt[1048576];
char s[1048576], t[1048576];

int get_id(mm &tbl, char *s)
{
	int res;
	mm::iterator it = tbl.find(s);
	if (it == tbl.end())
	{
		res = tbl.size();
		tbl[s] = res;
		par[res] = -1;
		cnt[res] = 1;
	}
	else
	{
		res = it->second;
	}
	return res;
}

int getpar(int cur)
{
	if (par[cur] == -1)
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

int mg(int a, int b)
{
	a = getpar(a);
	b = getpar(b);
	if (a != b)
	{
		par[a] = b;
		cnt[b] += cnt[a];
	}
	return cnt[b];
}

int main()
{
	int n, i, a, b;
	mm tbl;
	while (scanf("%d", &n) == 1)
	{
		tbl.clear();
		for (i=0; i<n; i++)
		{
			scanf("%s%s", s, t);
			a = get_id(tbl, s);
			b = get_id(tbl, t);
			printf("%d\n", mg(a, b));
		}
	}
	return 0;
}
