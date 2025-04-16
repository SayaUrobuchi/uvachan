#include <iostream>
#include <vector>
using namespace std;
 
const int N = 200005;
const int N4 = (N << 2);
 
int ary[N];
long long cos[N4];
vector<int> lis[N4];
vector<long long> pre[N4];
 
void build(int l, int r, int cp, int ary[])
{
	if (l == r)
	{
		cos[cp] = 0;
		lis[cp].emplace_back(ary[l]);
		pre[cp].emplace_back(ary[l]);
		return;
	}
	int mid = ((l+r) >> 1);
	int lp = (cp << 1);
	int rp = (lp | 1);
	build(l, mid, lp, ary);
	build(mid+1, r, rp, ary);
	cos[cp] = cos[lp] + cos[rp];
	lis[cp] = lis[lp];
	pre[cp] = pre[lp];
	for (int i=0; i<lis[rp].size(); i++)
	{
		int cur = lis[rp][i];
		lis[cp].emplace_back(max(cur, lis[cp].back()));
		pre[cp].emplace_back(pre[cp].back() + lis[cp].back());
		cos[cp] += lis[cp].back() - cur;
	}
}
 
long long query(int l, int r, int cp, int ql, int qr, int &lin)
{
	long long ret = 0;
	if (ql <= l && qr >= r)
	{
		int idx = lower_bound(lis[cp].begin(), lis[cp].end(), lin) - lis[cp].begin();
		ret = cos[cp];
		if (idx > 0)
		{
			ret += lin * 1LL * idx - pre[cp][idx-1];
		}
		lin = max(lin, lis[cp].back());
		return ret;
	}
	int mid = ((l+r) >> 1);
	int lp = (cp << 1);
	int rp = (lp | 1);
	if (ql <= mid)
	{
		ret += query(l, mid, lp, ql, qr, lin);
	}
	if (qr >= mid+1)
	{
		ret += query(mid+1, r, rp, ql, qr, lin);
	}
	return ret;
}
 
int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	build(1, n, 1, ary);
	for (i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int lin = 0;
		long long ans = query(1, n, 1, a, b, lin);
		printf("%lld\n", ans);
	}
	return 0;
}
