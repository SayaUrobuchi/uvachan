/*
ID: sa072682
LANG: C
TASK: crypt1
*/
#include <stdio.h>

int ary[10], n, ans, a, b, c, d, e, p, q, r, s, t, u, v, w, x;
char tbl[10], list[5];

void dfs(int depth)
{
	int i;
	if(depth == 5)
	{
		a = list[0];
		b = list[1];
		c = list[2];
		d = list[3];
		e = list[4];
		r = c * e;
		q = b * e;
		if(r > 9)
		{
			q += r / 10;
			r %= 10;
		}
		if(!tbl[r])
		{
			return;
		}
		p = a * e;
		if(q > 9)
		{
			p += q / 10;
			q %= 10;
		}
		if(p > 9 || !tbl[q] || !tbl[p])
		{
			return;
		}
		u = c * d;
		t = b * d;
		if(u > 9)
		{
			t += u / 10;
			u %= 10;
		}
		if(!tbl[u])
		{
			return;
		}
		s = a * d;
		if(t > 9)
		{
			s += t / 10;
			t %= 10;
		}
		if(s > 9 || !tbl[s] || !tbl[t])
		{
			return;
		}
		x = q + u;
		w = p + t;
		if(x > 9)
		{
			x -= 10;
			w++;
		}
		if(!tbl[x])
		{
			return;
		}
		v = s;
		if(w > 9)
		{
			w -= 10;
			v++;
		}
		if(v > 9 || !tbl[v] || !tbl[w])
		{
			return;
		}
		ans++;
		return;
	}
	for(i=0; i<n; i++)
	{
		if((depth || depth != 3) || ary[i])
		{
			list[depth] = ary[i];
			dfs(depth+1);
		}
	}
}

int main()
{
	int i;
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		tbl[ary[i]] = 1;
	}
	dfs(0);
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
