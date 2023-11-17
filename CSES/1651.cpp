#include <iostream>
using namespace std;
 
const int UPDATE = 1;
const int QUERY = 2;
const int N = 200005;
const int SEGN = (N<<2);
 
int n;
int ary[N];
long long seg[SEGN], add[SEGN];
 
void build(int cur, int l, int r)
{
	if (l == r)
	{
		seg[cur] = ary[l];
		return;
	}
	int mid = ((l+r) >> 1);
	int left = (cur<<1);
	int right = ((cur<<1)|1);
	build(left, l, mid);
	build(right, mid+1, r);
	seg[cur] = min(seg[left], seg[right]);
}
 
void push(int cur, int left, int right)
{
	add[left] += add[cur];
	seg[left] += add[cur];
	add[right] += add[cur];
	seg[right] += add[cur];
	add[cur] = 0;
}
 
void fix(int cur, int l, int r, int ql, int qr, int d)
{
	if (ql <= l && qr >= r)
	{
		seg[cur] += d;
		add[cur] += d;
		return;
	}
	int mid = ((l+r) >> 1);
	int left = (cur<<1);
	int right = ((cur<<1)|1);
	push(cur, left, right);
	if (ql <= mid)
	{
		fix(left, l, mid, ql, qr, d);
	}
	if (qr >= mid+1)
	{
		fix(right, mid+1, r, ql, qr, d);
	}
	seg[cur] = min(seg[left], seg[right]);
}
 
long long query(int cur, int l, int r, int ql, int qr)
{
	if (ql <= l && qr >= r)
	{
		return seg[cur];
	}
	int mid = ((l+r) >> 1);
	int left = (cur<<1);
	int right = ((cur<<1)|1);
	long long ret = 9e18;
	push(cur, left, right);
	if (ql <= mid)
	{
		ret = min(ret, query(left, l, mid, ql, qr));
	}
	if (qr >= mid+1)
	{
		ret = min(ret, query(right, mid+1, r, ql, qr));
	}
	return ret;
}
 
int main()
{
	int m, i, cmd, a, b, c;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	build(1, 1, n);
	for (i=0; i<m; i++)
	{
		scanf("%d", &cmd);
		if (cmd == UPDATE)
		{
			scanf("%d%d%d", &a, &b, &c);
			fix(1, 1, n, a, b, c);
		}
		else
		{
			scanf("%d", &a);
			long long ret = query(1, 1, n, a, a);
			printf("%lld\n", ret);
		}
	}
	return 0;
}
