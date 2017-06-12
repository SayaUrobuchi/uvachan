#include <stdio.h>
#include <string.h>

struct node
{
	int wei, n;
};

node heap[50000];
short map[20000][70];
char num[20000], con[20000];
int dis[20000], wei[20000][70], hn;

void heapdown(int n)
{
	node tmp;
	int l, r;
	l = n * 2;
	if(l <= hn)
	{
		r = l + 1;
		if(r > hn || heap[l].wei < heap[r].wei)
		{
			if(heap[n].wei > heap[l].wei)
			{
				tmp = heap[n];
				heap[n] = heap[l];
				heap[l] = tmp;
				heapdown(l);
			}
		}
		else
		{
			if(heap[n].wei > heap[r].wei)
			{
				tmp = heap[n];
				heap[n] = heap[r];
				heap[r] = tmp;
				heapdown(r);
			}
		}
	}
}

void heapup(int n)
{
	node tmp;
	if(n == 1)
	{
		return;
	}
	if(heap[n].wei < heap[n/2].wei)
	{
		tmp = heap[n/2];
		heap[n/2] = heap[n];
		heap[n] = tmp;
		heapup(n/2);
	}
}

node pop()
{
	heap[0] = heap[1];
	heap[1] = heap[hn--];
	heapdown(1);
	return heap[0];
}

void push(int n, int w)
{
	heap[++hn].n = n;
	heap[hn].wei = w;
	heapup(hn);
}

int main()
{
	int cas, count, n, m, s, t, i, j, k, w, nn, lim;
	node now;
	scanf("%d", &count);
	for(cas=1, count++; cas<count; cas++)
	{
		scanf("%d%d%d%d", &n, &m, &s, &t);
		memset(num, 0, n);
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			map[i][num[i]] = j;
			wei[i][num[i]++] = k;
			map[j][num[j]] = i;
			wei[j][num[j]++] = k;
		}
		memset(con, 1, n);
		memset(dis, 0, 4 * n);
		con[s] = 0;
		hn = 0;
		for(i=0, lim=num[s]; i<lim; i++)
		{
			push(map[s][i], wei[s][i]);
			dis[map[s][i]] = wei[s][i];
		}
		while(hn)
		{
			now = pop();
			nn = now.n;
			if(con[nn])
			{
				w = now.wei;
				con[nn] = 0;
				if(nn == t)
				{
					break;
				}
				for(i=0, lim=num[nn]; i<lim; i++)
				{
					if(con[map[nn][i]] && (dis[map[nn][i]] > w + wei[nn][i] || !dis[map[nn][i]]))
					{
						dis[map[nn][i]] = w + wei[nn][i];
						push(map[nn][i], dis[map[nn][i]]);
					}
				}
			}
		}
		if(con[t])
		{
			printf("Case #%d: unreachable\n", cas);
		}
		else
		{
			printf("Case #%d: %d\n", cas, w);
		}
	}
	return 0;
}
