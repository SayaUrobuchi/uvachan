#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int id[100000], used[100000], m, sbit, nbit;
char map[150][150], *ptr, s[100000];

typedef struct abcc
{
	char *h, *t;
	int arr[4];
}node;

node nptr[100000];

int min(int p, int q)
{
	return p<q ? p : q;
}

int scmp(char *p, int pl, char *q, int ql)
{
	return pl == ql ? strncmp(p, q, pl) : pl-ql;
}

int comp(const void *p, const void *q)
{
	return scmp(nptr[*(int*)p].h, nptr[*(int*)p].t-nptr[*(int*)p].h, nptr[*(int*)q].h, nptr[*(int*)q].t-nptr[*(int*)q].h);
}

void divide(int x1, int y1, int x2, int y2)
{
	int i, j, now, cx, cy;
	for(i=x1; i<=x2; i++)
	{
		for(j=y1; j<=y2; j++)
		{
			if(map[i][j] != map[x1][y1])
			{
				break;
			}
		}
		if(j <= y2)
		{
			break;
		}
	}
	if(i <= x2)
	{
		id[m] = m;
		nptr[now=m++].h = ptr;
		*(ptr++) = 'D';
		cx = ((x1+x2)>>1);
		cy = ((y1+y2)>>1);
		nptr[now].arr[0] = m;
		divide(x1, y1, cx, cy);
		nptr[now].arr[1] = m;
		divide(x1, cy+1, cx, y2);
		nptr[now].arr[2] = m;
		divide(cx+1, y1, x2, cy);
		nptr[now].arr[3] = m;
		divide(cx+1, cy+1, x2, y2);
		nptr[now].t = ptr;
	}
	else
	{
		id[m] = m;
		nptr[m++].h = ptr;
		*(ptr++) = map[x1][y1];
		nptr[m-1].t = ptr;
	}
}

int bis(int left, int right, char* s, int len)
{
	int center, cmp;
	center = ((left + right) >> 1);
	if((cmp=scmp(s, len, nptr[id[center]].h, nptr[id[center]].t-nptr[id[center]].h)) == 0)
	{
		return id[center];
	}
	else if(cmp > 0)
	{
		return bis(center+1, right, s, len);
	}
	return bis(left, center-1, s, len);
}

void recur(int now)
{
	int tmp, l, i;
	if(*(nptr[now].h) == 'D')
	{
		tmp = bis(0, m-1, nptr[now].h, l=nptr[now].t-nptr[now].h);
		if(tmp == -1)
		{
			for(i=0; i<4; i++)
			{
				recur(nptr[now].arr[i]);
			}
		}
		else
		{
			if(used[tmp] == 0)
			{
				used[tmp] = 1;
				for(i=0; i<4; i++)
				{
					recur(nptr[now].arr[i]);
				}
			}
			else
			{
				sbit -= l;
			}
		}
	}
}

int main()
{
	int n, i;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		memset(map, '0', sizeof(map));
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for(i=0; ; i++)
		{
			if((1<<i) >= n && (1<<i) >= m)
			{
				break;
			}
		}
		n = (1<<i);
		for(i=0; i<n; i++)
		{
			map[i][m] = '0';
		}
		ptr = s;
		m = 0;
		divide(0, 0, n-1, n-1);
		/*puts(s);*/
		sbit = nbit = ptr - s;
		qsort(id, m, sizeof(int), comp);
		memset(used, 0, sizeof(used));
		recur(0);
		printf("%d %d\n", nbit, sbit);
	}
    return 0;
}
