#include <stdio.h>
#include <string.h>

int h, dis[100005], px[100005], py[100005], next[100005], pre[100005];

typedef struct hnode
{
	int id, dis;
}hnode;

hnode heap[1000005];

int ab(int now)
{
	return now < 0 ? -now : now;
}

int getdis(int p, int q)
{
	return (px[p]==px[q] || py[p]==py[q]) ? ab(px[p]-px[q])+ab(py[p]-py[q]) : 2147483647;
}

int comp(hnode p, hnode q)
{
	return p.dis - q.dis;
}

void swap(hnode *p, hnode *q)
{
	hnode temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void heapup(int now)
{
	int parent;
	parent = (now >> 1);
	if(parent)
	{
		if(comp(heap[parent], heap[now]) > 0)
		{
			swap(heap+parent, heap+now);
			heapup(parent);
		}
	}
}

void heapdown(int now)
{
	int left, right;
	left = now + now;
	right = left + 1;
	if(left < h)
	{
		if(right >= h || comp(heap[left], heap[right]) < 0)
		{
			if(comp(heap[left], heap[now]) < 0)
			{
				swap(heap+left, heap+now);
				heapdown(left);
			}
		}
		else
		{
			if(comp(heap[right], heap[now]) < 0)
			{
				swap(heap+right, heap+now);
				heapdown(right);
			}
		}
	}
}

void push(int id, int dis)
{
	heap[h++] = (hnode){id, dis};
	heapup(h-1);
}

hnode pop()
{
	if(h == 1)
	{
		heap[0].id = -1;
		return heap[0];
	}
	heap[0] = heap[1];
	heap[1] = heap[--h];
	heapdown(1);
	return heap[0];
}

int main()
{
	int count, n, i, j, min;
	hnode temp;
	long long res;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			next[i-1] = i;
			pre[i-1] = i-2;
		}
		next[i-1] = 0;
		pre[i-1] = i-2;
		h = 1;
		for(i=2; i<=n; i++)
		{
			dis[i] = getdis(1, i);
			if(dis[i] != 2147483647)
			{
				push(i, dis[i]);
			}
		}
		res = 0;
		while((temp=pop()).id != -1)
		{
			if(next[temp.id] == -2)
			{
				continue;
			}
			next[pre[temp.id]] = next[temp.id];
			pre[next[temp.id]] = pre[temp.id];
			next[temp.id] = -2;
			res += temp.dis;
			for(i=0; j=next[i]; i=j)
			{
				if((min=getdis(temp.id, j)) < dis[j])
				{
					dis[j] = min;
					push(j, min);
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
