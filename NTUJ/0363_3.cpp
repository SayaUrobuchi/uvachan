#include <stdio.h>
#include <string.h>

#define MAXN 10005

int h, map[105][305], dis[105][105], time[105][105], num[105], used[105][MAXN], dd[105][MAXN];

typedef struct node
{
	int n, d, t;
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

void push(int n, int t, int d)
{
	heap[h++] = (node){n, d, t};
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
	int n, m, i, j, k, l, s, e, d, t, c, nn, next, last;
	node now;
	while(scanf("%d%d", &n, &m) == 2)
	{
		scanf("%d%d", &s, &e);
		while(m--)
		{
			scanf("%d%d%d%d", &i, &j, &k, &l);
			map[i][num[i]++] = j;
			map[j][num[j]++] = i;
			dis[i][j] = dis[j][i] = k;
			time[i][j] = time[j][i] = l;
		}
		memset(used, 0, sizeof(used));
		memset(dd, 1, sizeof(dd));
		h = 1;
		push(s, 0, 0);
		dd[s][0] = 0;
		while(pop())
		{
			now = heap[0];
			nn = now.n;
			d = now.d;
			t = now.t;
			if(used[nn][t] == 0)
			{
				used[nn][t] = 1;
				for(i=0; i<num[nn]; i++)
				{
					next = map[nn][i];
					if(used[next][t+time[nn][next]] == 0 && dd[next][t+time[nn][next]] > d+dis[nn][next])
					{
						for(j=1; j<t+time[nn][next]; j++)
						{
							if(d+dis[nn][next] > dd[next][j])
							{
								break;
							}
						}
						if(j == t+time[nn][next])
						{
							dd[next][t+time[nn][next]] = d+dis[nn][next];
							push(next, t+time[nn][next], d+dis[nn][next]);
						}
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
