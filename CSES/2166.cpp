#include <iostream>
using namespace std;
 
const int REPLACE = 1;
const int QUERY = 2;
const int N = 200005;
const int SEGN = (N<<2);
 
int ary[N];
long long seg[SEGN], laz[SEGN];
 
void push_laz(int cur, int left, int right)
{
	laz[left] += laz[cur];
	seg[left] += laz[cur];
	laz[right] += laz[cur];
	seg[right] += laz[cur];
	laz[cur] = 0;
}
 
void add(int cur, int l, int r, int ql, int qr, int d)
{
	if (ql <= l && qr >= r)
	{
		laz[cur] += d;
		seg[cur] += d;
		return;
	}
	int mid = ((l+r) >> 1);
	int left = (cur << 1);
	int right = (left | 1);
	push_laz(cur, left, right);
	if (ql <= mid)
	{
		add(left, l, mid, ql, qr, d);
	}
	if (qr >= mid + 1)
	{
		add(right, mid+1, r, ql, qr, d);
	}
	seg[cur] = max(seg[left], seg[right]);
}
 
long long query(int cur, int l, int r, int ql, int qr)
{
	if (ql < 1)
	{
		return 0;
	}
	if (ql <= l && qr >= r)
	{
		return seg[cur];
	}
	int mid = ((l+r) >> 1);
	int left = (cur << 1);
	int right = (left | 1);
	push_laz(cur, left, right);
	long long ret = -1e18;
	if (ql <= mid)
	{
		ret = max(ret, query(left, l, mid, ql, qr));
	}
	if (qr >= mid + 1)
	{
		ret = max(ret, query(right, mid+1, r, ql, qr));
	}
	return ret;
}
 
int main()
{
	int n, m, i, a, b, cmd;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		add(1, 1, n, i, n, ary[i]);
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d", &cmd, &a, &b);
		if (cmd == REPLACE)
		{
			add(1, 1, n, a, n, b-ary[a]);
			ary[a] = b;
		}
		else
		{
			long long ret = query(1, 1, n, a, b) - query(1, 1, n, a-1, a-1);
			printf("%lld\n", max(0LL, ret));
		}
	}
	return 0;
}
