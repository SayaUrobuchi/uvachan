#include <stdio.h>
#include <string.h>

int cir[1005], gg[1005], tbl[1005][1005];
long long tree[1005][3005];

int gcd(int p, int q)
{
	if(p%q)
	{
		return gcd(q, p%q);
	}
	return q;
}

void insert(long long *ary, int idx, int l, int r, int p, int q, int v)
{
	int c;
	if(p <= l && q >= r)
	{
		ary[idx] += v;
		return;
	}
	c = ((l+r)>>1);
	if(q >= l && c >= p)
	{
		insert(ary, idx<<1, l, c, p, q, v);
	}
	if(q >= c+1 && r >= p)
	{
		insert(ary, (idx<<1)+1, c+1, r, p, q, v);
	}
}

long long get_val(long long *ary, int idx, int l, int r, int p, int q)
{
	int c;
	long long res;
	if(p <= l && q >= r)
	{
		return ary[idx];
	}
	c = ((l+r)>>1);
	res = ary[idx];
	if(q >= l && c >= p)
	{
		res += get_val(ary, idx<<1, l, c, p, q);
	}
	if(q >= c+1 && r >= p)
	{
		res += get_val(ary, (idx<<1)+1, c+1, r, p, q);
	}
	return res;
}

int main()
{
	int count, i, j, k, l, c, d, t, st, dif, tim, n, m;
	long long res;
	scanf("%d", &count);
	cir[0] = 1;
	gg[0] = 1000;
	for(i=1; i<1000; i++)
	{
		cir[i] = 1000/(gg[i]=gcd(1000, i));
		for(j=0; j<gg[i]; j++)
		{
			for(k=0, l=j; k<cir[i]; k++)
			{
				tbl[i][l] = k;
				l += i;
				if(l >= 1000)
				{
					l -= 1000;
				}
			}
		}
	}
	while(count--)
	{
		scanf("%d", &n);
		memset(tree, 0, sizeof(tree));
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &st, &dif, &tim);
			st %= 1000;
			dif %= 1000;
			c = st%gg[dif];
			d = tbl[dif][st];
			insert(tree[dif], 1, 0, 999, c*cir[dif], (c+1)*cir[dif]-1, tim/cir[dif]);
			t = tim%cir[dif];
			if(t)
			{
				if(d+t-1 >= cir[dif])
				{
					insert(tree[dif], 1, 0, 999, c*cir[dif]+d, (c+1)*cir[dif]-1, 1);
					insert(tree[dif], 1, 0, 999, c*cir[dif], c*cir[dif]+d+t-1-cir[dif], 1);
				}
				else
				{
					insert(tree[dif], 1, 0, 999, c*cir[dif]+d, c*cir[dif]+d+t-1, 1);
				}
			}
		}
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d", &t);
			for(j=0, res=0; j<1000; j++)
			{
				c = t%gg[j];
				d = tbl[j][t];
				res += get_val(tree[j], 1, 0, 999, c*cir[j]+d, c*cir[j]+d);
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
