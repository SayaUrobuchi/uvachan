#include <stdio.h>
#include <stdlib.h>
#include <map>

int lim;
int ary[5][5];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int stk[102400];
int hc, cc;

struct hd
{
	int x, y, s, b;
	unsigned long long v;
};

struct hd h[10485760];

struct qd
{
	int a, b;
};

struct qd qu[10485760];
std::map<unsigned long long, int> tbl;

int t(char *s)
{
	if (*s == '*')
	{
		return 0;
	}
	return atoi(s);
}

int calc(int x, int y, int n)
{
	if (n == 0)
	{
		return 0;
	}
	--n;
	int p = x-(n>>2);
	int q = y-(n&3);
	if (p < 0)
	{
		p = -p;
	}
	if (q < 0)
	{
		q = -q;
	}
	return p+q;
}

void hup(int idx)
{
	int t;
	struct hd temp;
	while (idx > 1)
	{
		t = (idx >> 1);
		if (h[t].s > h[idx].s)
		{
			temp = h[t];
			h[t] = h[idx];
			h[idx] = temp;
			idx = t;
		}
		else
		{
			return;
		}
	}
}

void hdown(int idx)
{
	int t, nx;
	struct hd temp;
	while ((t = (idx<<1)) <= hc)
	{
		if (t == hc || h[t].s < h[t+1].s)
		{
			nx = t;
		}
		else
		{
			nx = t+1;
		}
		if (h[nx].s < h[idx].s)
		{
			temp = h[nx];
			h[nx] = h[idx];
			h[idx] = temp;
			idx = nx;
		}
		else
		{
			return;
		}
	}
}

void pop()
{
	h[0] = h[1];
	h[1] = h[hc];
	hc--;
	hdown(1);
}

int main()
{
	char s[16];
	int i, j, p, q, dis, x, y, tx, ty, ts, temp;
	unsigned long long v, tv, m;
	while(scanf("%s", s) == 1)
	{
		ary[0][0] = t(s);
		p = 0;
		q = 0;
		dis = calc(0, 0, ary[0][0]);
		v = ary[0][0];
		for (i=0; i<4; i++)
		{
			for (j=0; j<4; j++)
			{
				if (i+j)
				{
					scanf("%s", s);
					ary[i][j] = t(s);
					if (ary[i][j] == 0)
					{
						p = i;
						q = j;
					}
					dis += calc(i, j, ary[i][j]);
					v += (1LLU<<((i<<4)+(j<<2))) * ary[i][j];
				}
			}
		}
		h[1].x = p;
		h[1].y = q;
		h[1].s = dis;
		h[1].b = -1;
		h[1].v = v;
		tbl.clear();
		tbl[v] = 1;
		hc = 1;
		cc = 0;
		qu[cc].a = 0;
		qu[cc].b = -1;
		while(1)
		{
			pop();
			if (h[0].s == 0)
			{
				break;
			}
			x = h[0].x;
			y = h[0].y;
			v = h[0].v;
			/*if (hc < 30)
			{
				for (i=0; i<4; i++)
				{
					for (j=0; j<4; j++)
					{
						temp = ((v & (15 * (1LLU<<((i<<4)+(j<<2))))) >> ((i<<4)+(j<<2)));
						printf("%d ", temp);
					}
					printf("\n");
				}
				printf("\n");
			}*/
			for (i=0; i<4; i++)
			{
				tx = x + dx[i];
				ty = y + dy[i];
				if (tx >= 0 && tx < 4 && ty >= 0 && ty < 4)
				{
					m = (15 * (1LLU<<((tx<<4)+(ty<<2))));
					temp = ((v & m) >> ((tx<<4)+(ty<<2)));
					m += (15 * (1LLU<<((x<<4)+(y<<2))));
					tv = (v & ~m) + temp * (1LLU<<((x<<4)+(y<<2)));
					if (!tbl[tv])
					{
						tbl[tv] = 1;
						ts = h[0].s - calc(tx, ty, temp) + calc(x, y, temp);
						hc++;
						cc++;
						h[hc].x = tx;
						h[hc].y = ty;
						h[hc].s = ts;
						h[hc].b = cc;
						h[hc].v = tv;
						hup(hc);
						qu[cc].a = temp;
						qu[cc].b = h[0].b;
					}
				}
			}
		}
		for (i=0, j=h[0].b; j>=0; j=qu[j].b, i++)
		{
			stk[i] = qu[j].a;
		}
		for (i--; i>=0; i--)
		{
			printf("%d\n", stk[i]);
		}
	}
	return 0;
}