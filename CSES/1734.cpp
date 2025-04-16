#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pp = pair<int, int>;
 
const int N = 200005;
const int N4 = (N << 2);
 
int nxt[N];
pp ary[N];
vector<int> lis[N4];
 
void build(int l, int r, int cp)
{
	if (l == r)
	{
		lis[cp].emplace_back(nxt[l]);
		return;
	}
	int mid = ((l+r) >> 1);
	int lp = (cp << 1);
	int rp = (lp | 1);
	build(l, mid, lp);
	build(mid+1, r, rp);
	int a = 0;
	int b = 0;
	while (a < lis[lp].size() || b < lis[rp].size())
	{
		if (b >= lis[rp].size() || (a < lis[lp].size() && lis[lp][a] < lis[rp][b]))
		{
			lis[cp].emplace_back(lis[lp][a++]);
		}
		else
		{
			lis[cp].emplace_back(lis[rp][b++]);
		}
	}
}
 
int query(int l, int r, int cp, int ql, int qr)
{
	int ret = 0;
	if (ql <= l && qr >= r)
	{
		int rep = upper_bound(lis[cp].begin(), lis[cp].end(), qr) - lis[cp].begin();
		ret = (r - l + 1) - rep;
		return ret;
	}
	int mid = ((l+r) >> 1);
	int lp = (cp << 1);
	int rp = (lp | 1);
	if (ql <= mid)
	{
		ret += query(l, mid, lp, ql, qr);
	}
	if (qr >= mid+1)
	{
		ret += query(mid+1, r, rp, ql, qr);
	}
	return ret;
}
 
int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i].first);
		ary[i].second = i;
	}
	sort(ary+1, ary+1+n);
	for (i=1; i<=n; i++)
	{
		int t = ary[i+1].second;
		if (i+1 > n || ary[i+1].first != ary[i].first)
		{
			t = n + 1;
		}
		nxt[ary[i].second] = t;
	}
	build(1, n, 1);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int ans = query(1, n, 1, a, b);
		printf("%d\n", ans);
	}
	return 0;
}
