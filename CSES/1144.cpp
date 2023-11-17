#include <iostream>
#include <vector>
using namespace std;
 
const int N = 200005;
const int ROOT = 1;
const int NONE = 0;
const int MAXR = 1e9;
const char CHANGE = '!';
const char QUERY = '?';
 
struct node
{
	int l, r;
	int v;
};
 
int ary[N];
vector<node> seg;
 
void gen(int &p)
{
	p = seg.size();
	seg.push_back({NONE, NONE, 0});
}
 
void add(int cur, int l, int r, int pos, int d)
{
	seg[cur].v += d;
	if (l == r)
	{
		return;
	}
	int mid = ((l+r) >> 1);
	if (pos <= mid)
	{
		if (seg[cur].l == NONE)
		{
			gen(seg[cur].l);
		}
		add(seg[cur].l, l, mid, pos, d);
	}
	else
	{
		if (seg[cur].r == NONE)
		{
			gen(seg[cur].r);
		}
		add(seg[cur].r, mid+1, r, pos, d);
	}
}
 
int query(int cur, int l, int r, int ql, int qr)
{
	if (ql <= l && qr >= r)
	{
		return seg[cur].v;
	}
	int mid = ((l+r) >> 1);
	int lv = 0;
	int rv = 0;
	if (ql <= mid && seg[cur].l != NONE)
	{
		lv = query(seg[cur].l, l, mid, ql, qr);
	}
	if (qr >= mid + 1 && seg[cur].r != NONE)
	{
		rv = query(seg[cur].r, mid+1, r, ql, qr);
	}
	return lv + rv;
}
 
int main()
{
	int n, m, i, a, b;
	char cmd[8];
	scanf("%d%d", &n, &m);
	seg.resize(ROOT+1);
	seg[ROOT].l = seg[ROOT].r = NONE;
	seg[ROOT].v = 0;
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		add(ROOT, 1, MAXR, ary[i], 1);
	}
	for (i=0; i<m; i++)
	{
		scanf("%s%d%d", cmd, &a, &b);
		if (*cmd == CHANGE)
		{
			add(ROOT, 1, MAXR, ary[a], -1);
			ary[a] = b;
			add(ROOT, 1, MAXR, ary[a], 1);
		}
		else
		{
			int ret = query(ROOT, 1, MAXR, a, b);
			printf("%d\n", ret);
		}
	}
	return 0;
}
