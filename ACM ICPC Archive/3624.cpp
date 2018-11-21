#include <stdio.h>
#include <string.h>

int tt;
int pcnt, ptbl[20000];
int hn, htbl[55], heap[55];
int map[55][55], mdis[55][55], num[55];
int ptt[55], cnt[55];

typedef struct data
{
	int dis;
	int path[55], plen;
	int htbl[55];
	int loc;
}data;

data pool[20000], *kdis[55][205];

void pool_init()
{
	int i;
	pcnt = 20000;
	for(i=0; i<20000; i++)
	{
		ptbl[i] = i;
		pool[i].loc = i;
	}
}

data *get_data()
{
	int t;
	t = ptbl[0];
	ptbl[0] = ptbl[--pcnt];
	return pool+t;
}

int dcomp(data *p, data *q)
{
	int i;
	if(p->dis != q->dis)
	{
		return p->dis - q->dis;
	}
	for(i=0; i<p->plen&&i<q->plen; i++)
	{
		if(p->path[i] != q->path[i])
		{
			return p->path[i] - q->path[i];
		}
	}
	return p->plen - q->plen;
}

void h_init()
{
	hn = 1;
	memset(htbl, 0, sizeof(htbl));
}

void hswap(int p, int q)
{
	int t;
	t = heap[p];
	heap[p] = heap[q];
	heap[q] = t;
	htbl[heap[p]] = p;
	htbl[heap[q]] = q;
}

int hcomp(int p, int q)
{
	p = heap[p];
	q = heap[q];
	if(cnt[p] == ptt[p])
	{
		return 1;
	}
	if(cnt[q] == ptt[q])
	{
		return -1;
	}
	return dcomp(kdis[p][cnt[p]], kdis[q][cnt[q]]);
}

void heapup(int now)
{
	int par;
	par = (now>>1);
	if(par)
	{
		if(hcomp(now, par) < 0)
		{
			hswap(now, par);
			heapup(par);
		}
	}
}

void heapdown(int now)
{
	int left, right;
	left = (now<<1);
	right = left + 1;
	if(left < hn)
	{
		if(right >= hn || hcomp(left, right) < 0)
		{
			if(hcomp(now, left) > 0)
			{
				hswap(now, left);
				heapdown(left);
			}
		}
		else
		{
			if(hcomp(now, right) > 0)
			{
				hswap(now, right);
				heapdown(right);
			}
		}
	}
}

void hpush(int t)
{
	if(htbl[t])
	{
		heapup(htbl[t]);
		heapdown(htbl[t]);
	}
	else
	{
		htbl[t] = hn;
		heap[hn] = t;
		hn++;
		heapup(hn-1);
	}
}

int hpop()
{
	if(cnt[heap[1]] == ptt[heap[1]])
	{
		return -1;
	}
	return heap[1];
}

void adj(int t)
{
	int i;
	data *temp;
	for(i=ptt[t]; i>0; i--)
	{
		if(dcomp(kdis[t][i], kdis[t][i-1]) < 0)
		{
			temp = kdis[t][i];
			kdis[t][i] = kdis[t][i-1];
			kdis[t][i-1] = temp;
		}
		else
		{
			break;
		}
	}
	if(ptt[t] < tt)
	{
		ptt[t]++;
	}
	else
	{
		ptbl[pcnt++] = kdis[t][tt]->loc;
	}
	if(i == cnt[t])
	{
		hpush(t);
	}
}

int main()
{
	int n, m, st, ed, i, p, q, r, c, nx, pp;
	data *pd, *nd;
	while(scanf("%d%d%d%d%d", &n, &m, &tt, &st, &ed) == 5)
	{
		if(n == 0 && m == 0 && tt == 0 && st == 0 && ed == 0)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			map[p][num[p]] = q;
			mdis[p][num[p]] = r;
			num[p]++;
		}
		memset(ptt, 0, sizeof(ptt));
		ptt[st] = 1;
		pool_init();
		kdis[st][0] = get_data();
		kdis[st][0]->dis = 0;
		kdis[st][0]->path[0] = st;
		kdis[st][0]->plen = 1;
		memset(kdis[st][0]->htbl, 0, sizeof(pool[0].htbl));
		kdis[st][0]->htbl[st] = 1;
		h_init();
		memset(cnt, 0, sizeof(cnt));
		hpush(st);
		while(p=hpop())
		{
			if(p == -1)
			{
				break;
			}
			if(p == ed && cnt[p] == tt-1)
			{
				break;
			}
			pd = kdis[p][cnt[p]];
			cnt[p]++;
			hpush(p);
			for(i=0; i<num[p]; i++)
			{
				nx = map[p][i];
				pp = ptt[nx];
				if(pd->htbl[nx] == 0)
				{
					nd = kdis[nx][pp] = get_data();
					nd->dis = pd->dis + mdis[p][i];
					memcpy(nd->path, pd->path, sizeof(int)*pd->plen);
					nd->plen = pd->plen + 1;
					nd->path[pd->plen] = nx;
					memcpy(nd->htbl, pd->htbl, sizeof(pool[0].htbl));
					nd->htbl[nx] = 1;
					adj(nx);
				}
			}
		}
		if(p == -1)
		{
			printf("None\n");
		}
		else
		{
			pd = kdis[p][tt-1];
			printf("%d", pd->path[0]);
			for(i=1; i<pd->plen; i++)
			{
				printf("-%d", pd->path[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
