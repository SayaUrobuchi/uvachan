#include <stdio.h>
#include <string.h>

int tbl[5000000][10], bon[5000000];
char str[10000000];

int min(int p, int q)
{
	return p<q ? p : q;
}

int max(int p, int q)
{
	return p>q ? p : q;
}

void init(int nod, int p, int q)
{
	int c, i;
	if(p == q)
	{
		memset(tbl[nod], 0, sizeof(tbl[0]));
		tbl[nod][str[p]-'0']++;
		bon[nod] = 0;
		return;
	}
	c = ((p+q)>>1);
	init(nod<<1, p, c);
	init((nod<<1)+1, c+1, q);
	for(i=0; i<10; i++)
	{
		tbl[nod][i] = tbl[nod<<1][i] + tbl[(nod<<1)+1][i];
	}
	bon[nod] = 0;
}

int add(int now, int l, int r, int p, int q, int len)
{
	int t, i, temp, c;
	if(l == p && r == q)
	{
		for(i=0, temp=0; i<10; i++)
		{
			temp += tbl[now][i] * ((i+len+bon[now]) % 10);
		}
		bon[now]++;
		return temp;
	}
	c = ((l+r)>>1);
	temp = 0;
	if(p <= c)
	{
		temp += add(now<<1, l, c, max(l, p), min(c, q), len+bon[now]);
	}
	if(q >= c+1)
	{
		temp += add((now<<1)+1, c+1, r, max(c+1, p), min(r, q), len+bon[now]);
	}
	for(i=0; i<10; i++)
	{
		tbl[now][i] = 0;
	}
	for(i=0; i<10; i++)
	{
		tbl[now][(i+bon[now<<1])%10] += tbl[now<<1][i];
		tbl[now][(i+bon[(now<<1)+1])%10] += tbl[(now<<1)+1][i];
	}
	return temp;
}

int main()
{
	int n, m, i, p, q;
	while(scanf("%d%d", &n, &m) == 2)
	{
		scanf("%s", str+1);
		init(1, 1, n);
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			printf("%d\n", add(1, 1, n, p, q, 0));
		}
	}
	return 0;
}
