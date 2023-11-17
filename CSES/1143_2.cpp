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
 
int query(int cur, int l, int r, int q)
{
	if (l == r)
	{
		if (seg[cur] < q)
		{
			return GG;
		}
		return l;
	}
	int mid = ((l+r) >> 1);
	int left = (cur<<1);
	int right = ((cur<<1)|1);
	int ret = 0;
	if (seg[left] >= q)
	{
		return query(left, l, mid, q);
	}
	return query(right, mid+1, r, q);
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
		int ans = query(1, 1, n, q);
		if (ans != GG)
		{
			fix(1, 1, n, ans, -q);
		}
		printf("%s%d", i?" ":"", ans);
	}
	puts("");
	return 0;
}
