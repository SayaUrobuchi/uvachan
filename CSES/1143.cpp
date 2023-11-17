#include <iostream>
using namespace std;
 
const int GG = 0;
const int N = 200005;
 
int n;
int ary[N], seg[N<<2];
 
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
	seg[cur] = max(seg[left], seg[right]);
}
 
void fix(int cur, int l, int r, int pos, int v)
{
	if (l == r)
	{
		seg[cur] += v;
		return;
	}
	int mid = ((l+r) >> 1);
	int left = (cur<<1);
	int right = ((cur<<1)|1);
	if (pos <= mid)
	{
		fix(left, l, mid, pos, v);
	}
	else
	{
		fix(right, mid+1, r, pos, v);
	}
	seg[cur] = max(seg[left], seg[right]);
}
 
int query(int cur, int l, int r, int ql, int qr)
{
	if (ql <= l && qr >= r)
	{
		return seg[cur];
	}
	int mid = ((l+r) >> 1);
	int left = (cur<<1);
	int right = ((cur<<1)|1);
	int ret = 0;
	if (ql <= mid)
	{
		ret = max(ret, query(left, l, mid, ql, qr));
	}
	if (qr >= mid+1)
	{
		ret = max(ret, query(right, mid+1, r, ql, qr));
	}
	return ret;
}
 
int main()
{
	int m, i, q, l, r;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	build(1, 1, n);
	for (i=0; i<m; i++)
	{
		scanf("%d", &q);
		int ans = GG;
		for (l=1, r=n; l<=r; )
		{
			int mid = ((l+r) >> 1);
			int ret = query(1, 1, n, 1, mid);
			if (ret >= q)
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		if (ans != GG)
		{
			fix(1, 1, n, ans, -q);
		}
		printf("%s%d", i?" ":"", ans);
	}
	puts("");
	return 0;
}
