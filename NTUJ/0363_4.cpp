#include <stdio.h>
#include <string.h>

#define MAXN 2005

int h, map[105][305], dis[105][105], time[105][105], num[105], used[105][MAXN], dd[105][MAXN], ta[4], list[305][2];

typedef struct node
{
	int n, d, t, st[4];
}node;

node heap[1000001];

int comp(node p, node q)
{
	if(p.d == q.d)
	{
		return p.t-q.t;
	}
	return p.d-q.d;
}

void heapup(int now)
{
	int parent;
	node temp;
	parent = (now >> 1);
	if(parent)
	{
		if(comp(heap[now], heap[parent]) < 0)
		{
			temp = heap[now];
			heap[now] = heap[parent];
			heap[parent] = temp;
			heapup(parent);
		}
	}
}

void heapdown(int now)
{
	int left, right;
	node temp;
	left = (now<<1);
	right = left + 1;
	if(left < h)
	{
		if(right >= h || comp(heap[left], heap[right]) < 0)
		{
			if(comp(heap[left], heap[now]) < 0)
			{
				temp = heap[left];
				heap[left] = heap[now];
				heap[now] = temp;
				heapdown(left);
			}
		}
		else
		{
			if(comp(heap[right], heap[now]) < 0)
			{
				temp = heap[right];
				heap[right] = heap[now];
				heap[now] = temp;
				heapdown(right);
			}
		}
	}
}

void push(int n, int t, int d, int* a)
{
	heap[h++] = (node){n, d, t, {a[0], a[1], a[2], a[3]}};
	heapup(h-1);
}

int pop()
{
	if(h == 1)
	{
		return 0;
	}
	heap[0] = heap[1];
	heap[1] = heap[--h];
	heapdown(1);
	return 1;
}

int main()
{
	int n, m, i, j, k, l, s, e, d, t, c, p, q, nn, next, last, eg;
	node now;
	while(scanf("%d%d", &n, &m) == 2)
	{
		scanf("%d%d", &s, &e);
		eg = 0;
		while(m--)
		{
			scanf("%d%d%d%d", &i, &j, &k, &l);
			map[i][num[i]++] = j;
			map[j][num[j]++] = i;
			list[eg][0] = i;
			list[eg++][1] = j;
			dis[i][j] = dis[j][i] = k;
			time[i][j] = time[j][i] = l;
		}
		memset(dd, 1, sizeof(dd));
		dd[s][0] = 0;
		for(i=1; i<n; i++)
		{
			for(j=0; j<eg; j++)
			{
				p = list[j][0], q=list[j][1];
				for(k=0; k+time[p][q]<MAXN; k++)
				{
					if(dd[p][k+time[p][q]] > dd[q][k] + dis[q][p])
					{
						dd[p][k+time[p][q]] = dd[q][k] + dis[q][p];
					}
					if(dd[q][k+time[p][q]] > dd[p][k] + dis[q][p])
					{
						dd[q][k+time[p][q]] = dd[p][k] + dis[q][p];
					}
				}
			}
		}
		for(i=0, last=MAXN, c=0; i<MAXN; i++)
		{
			if(dd[e][i] < last)
			{
				last = dd[e][i];
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
