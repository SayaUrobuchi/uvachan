#include <iostream>
using namespace std;

const int N = 200005;
const int N4 = (N<<2);

int ary[N], bry[N];
int as[N4], bs[N4];

int gcd(int a, int b)
{
	if (a > b)
	{
		swap(a, b);
	}
	if (!b)
	{
		return 0;
	}
	while ((a %= b) && (b %= a));
	return a+b;
}

void build(int buf[], int l, int r, int idx, int ary[])
{
	if (l == r)
	{
		buf[idx] = abs(ary[l]-ary[l+1]);
		return;
	}
	int mid = ((l+r) >> 1);
	int lt = (idx << 1);
	int rt = (lt | 1);
	build(buf, l, mid, lt, ary);
	build(buf, mid+1, r, rt, ary);
	buf[idx] = gcd(buf[lt], buf[rt]);
}

int query(int buf[], int ql, int qr, int l, int r, int idx)
{
	if (ql > qr)
	{
		return 0;
	}
	if (ql <= l && qr >= r)
	{
		return buf[idx];
	}
	int mid = ((l+r) >> 1);
	int lt = (idx << 1);
	int rt = (lt | 1);
	int a = 0, b = 0;
	if (ql <= mid)
	{
		a = query(buf, ql, qr, l, mid, lt);
	}
	if (qr > mid)
	{
		b = query(buf, ql, qr, mid+1, r, rt);
	}
	return gcd(a, b);
}

void read(int n, int ary[], int as[])
{
	int i;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	if (n > 1)
	{
		build(as, 0, n-2, 1, ary);
	}
}

int main()
{
	int n, m, i, a, b, x0, x1, y0, y1;
	while (scanf("%d%d", &n, &m) == 2)
	{
		read(n, ary, as);
		read(n, bry, bs);
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d%d", &x0, &x1, &y0, &y1);
			--x0;
			--y0;
			--x1;
			--y1;
			a = query(as, x0, x1-1, 0, n-2, 1);
			b = query(bs, y0, y1-1, 0, n-2, 1);
			printf("%d\n", gcd(ary[x0]+bry[y0], gcd(a, b)));
		}
	}
	return 0;
}

