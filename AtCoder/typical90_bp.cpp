#include <iostream>
#include <cstring>
using namespace std;

const int N = 131072;

int par[N];
long long seg[N<<2];

int getpar(int cur)
{
	if (par[cur] < 0)
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

void link(int a, int b)
{
	a = getpar(a);
	b = getpar(b);
	if (a != b)
	{
		par[a] = b;
	}
}

void update(int cur, int l, int r, int pos, int val)
{
	int mid;
	if (l == r)
	{
		seg[cur] = -val;
		if (pos & 1)
		{
			seg[cur] = -seg[cur];
		}
		return;
	}
	mid = ((l+r) >> 1);
	if (pos <= mid)
	{
		update(cur<<1, l, mid, pos, val);
	}
	else
	{
		update((cur<<1)|1, mid+1, r, pos, val);
	}
	seg[cur] = seg[cur<<1] + seg[(cur<<1)|1];
}

long long query(int cur, int l, int r, int ql, int qr)
{
	int mid;
	long long t;
	if (ql <= l && qr >= r)
	{
		return seg[cur];
	}
	mid = ((l+r) >> 1);
	t = 0;
	if (ql <= mid)
	{
		t += query(cur<<1, l, mid, ql, qr);
	}
	if (qr > mid)
	{
		t += query((cur<<1)|1, mid+1, r, ql, qr);
	}
	return t;
}

int main()
{
	int n, m, i, a, b, c, d;
	long long t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(par, -1, sizeof(par));
		memset(seg, 0, sizeof(seg));
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d%d", &c, &a, &b, &d);
			if (c == 0)
			{
				link(a, b);
				update(1, 1, n, a, d);
			}
			else
			{
				if (getpar(a) != getpar(b))
				{
					puts("Ambiguous");
				}
				else
				{
					t = 0;
					if (a != b)
					{
						t = query(1, 1, n, min(a, b), max(a, b)-1);
					}
					if (b & 1)
					{
						t = -t;
					}
					if (a > b)
					{
						t = -t;
					}
					if ((a-b) & 1)
					{
						t -= d;
					}
					else
					{
						t += d;
					}
					printf("%lld\n", t);
				}
			}
		}
	}
	return 0;
}
