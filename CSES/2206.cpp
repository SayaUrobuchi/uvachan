#include <iostream>
using namespace std;
using seg_t = long long;
using segc_t = int (*)(int, int);
 
const int N = 200005;
const int SEGN = (N << 2);
const int CHANGE = 1;
const int QUERY = 2;
 
int n;
int ary[N];
seg_t lly[SEGN], rry[SEGN];
 
int cl(int pos, int v)
{
	return pos + v;
}
 
int cr(int pos, int v)
{
	return (n-pos+1) + v;
}
 
void build(seg_t seg[], int cur, int l, int r, segc_t f)
{
	if (l == r)
	{
		seg[cur] = f(l, ary[l]);
		return;
	}
	int mid = ((l+r) >> 1);
	int left = (cur << 1);
	int right = (left | 1);
	build(seg, left, l, mid, f);
	build(seg, right, mid+1, r, f);
	seg[cur] = min(seg[left], seg[right]);
}
 
void add(seg_t seg[], int cur, int l, int r, int pos, int d)
{
	if (l == r)
	{
		seg[cur] += d;
		return;
	}
	int mid = ((l+r) >> 1);
	int left = (cur << 1);
	int right = (left | 1);
	if (pos <= mid)
	{
		add(seg, left, l, mid, pos, d);
	}
	else
	{
		add(seg, right, mid+1, r, pos, d);
	}
	seg[cur] = min(seg[left], seg[right]);
}
 
seg_t query(seg_t seg[], int cur, int l, int r, int ql, int qr)
{
	if (ql <= l && qr >= r)
	{
		return seg[cur];
	}
	int mid = ((l+r) >> 1);
	int left = (cur << 1);
	int right = (left | 1);
	seg_t ret = 1e18;
	if (ql <= mid)
	{
		ret = min(ret, query(seg, left, l, mid, ql, qr));
	}
	if (qr >= mid+1)
	{
		ret = min(ret, query(seg, right, mid+1, r, ql, qr));
	}
	return ret;
}
 
int main()
{
	int m, i;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	build(lly, 1, 1, n, cl);
	build(rry, 1, 1, n, cr);
	for (i=0; i<m; i++)
	{
		int cmd, a, b;
		scanf("%d", &cmd);
		if (cmd == CHANGE)
		{
			scanf("%d%d", &a, &b);
			add(lly, 1, 1, n, a, b-ary[a]);
			add(rry, 1, 1, n, a, b-ary[a]);
			ary[a] = b;
		}
		else
		{
			scanf("%d", &a);
			long long ll = query(lly, 1, 1, n, a, n) - cl(a, 0);
			long long rr = query(rry, 1, 1, n, 1, a) - cr(a, 0);
			printf("%lld\n", min(ll, rr));
		}
	}
	return 0;
}
