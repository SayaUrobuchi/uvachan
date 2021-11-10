#include <iostream>
#include <cstring>
using namespace std;

int seg[1048576<<2], v[1048576<<2];

int query(int cur, int l, int r, int ql, int qr)
{
	int t, mid;
	if (ql <= l && qr >= r)
	{
		return seg[cur];
	}
	t = v[cur];
	mid = ((l+r) >> 1);
	if (ql <= mid)
	{
		t = max(t, query(cur<<1, l, mid, ql, qr));
	}
	if (qr > mid)
	{
		t = max(t, query((cur<<1)|1, mid+1, r, ql, qr));
	}
	return t;
}

void update(int cur, int l, int r, int ql, int qr, int val)
{
	int mid;
	if (ql <= l && qr >= r)
	{
		seg[cur] = v[cur] = val;
		return;
	}
	mid = ((l+r) >> 1);
	if (ql <= mid)
	{
		update(cur<<1, l, mid, ql, qr, val);
		seg[cur] = max(seg[cur], seg[cur<<1]);
	}
	if (qr > mid)
	{
		update((cur<<1)|1, mid+1, r, ql, qr, val);
		seg[cur] = max(seg[cur], seg[(cur<<1)|1]);
	}
}

int main()
{
	int n, m, i, a, b, t;
	while (scanf("%d%d", &m, &n) == 2)
	{
		memset(seg, 0, sizeof(seg));
		memset(v, 0, sizeof(v));
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			t = query(1, 1, m, a, b);
			printf("%d\n", t+1);
			update(1, 1, m, a, b, t+1);
		}
	}
	return 0;
}
