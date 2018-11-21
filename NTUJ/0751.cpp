#include <stdio.h>
#include <string.h>

int n, m, o;
int seg[2500000], bon[2500000];

int max(int p, int q)
{
	return p>q ? p : q;
}

int min(int p, int q)
{
	return p<q ? p : q;
}

int chk(int now, int l, int r, int p, int q, int len)
{
	int c, t;
	if(l == p && r == q)
	{
		return seg[now]+bon[now]+len <= m;
	}
	c = ((l+r)>>1);
	t = 1;
	if(p <= c)
	{
		t &= chk(now<<1, l, c, max(l, p), min(c, q), len+bon[now]);
	}
	if(q >= c+1)
	{
		t &= chk((now<<1)+1, c+1, r, max(c+1, p), min(r, q), len+bon[now]);
	}
	return t;
}

int add(int now, int l, int r, int p, int q, int len, int dd)
{
	int c;
	if(l == p && r == q)
	{
		bon[now] += len;
		return seg[now]+bon[now];
	}
	c = ((l+r)>>1);
	if(p <= c)
	{
		seg[now] = max(add(now<<1, l, c, max(l, p), min(c, q), len, dd+bon[now]), seg[now]);
	}
	if(q >= c+1)
	{
		seg[now] = max(add((now<<1)+1, c+1, r, max(c+1, p), min(r, q), len, dd+bon[now]), seg[now]);
	}
	return seg[now]+bon[now];
}

int main()
{
	int i, p, q, r;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		memset(seg, 0, sizeof(seg));
		memset(bon, 0, sizeof(bon));
		for(i=0; i<o; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			q--;
			if(chk(1, 0, n, p, q, r))
			{
				add(1, 0, n, p, q, r, 0);
				printf("T\n");
			}
			else
			{
				printf("N\n");
			}
		}
	}
	return 0;
}
