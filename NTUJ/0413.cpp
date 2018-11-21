#include <stdio.h>
#include <stdlib.h>

int h;

typedef struct abcc
{
	int p, d;
}abcc;

abcc heap[30000], asdf[30000], *ptr;

int comp(const void *p, const void *q)
{
	return ((abcc*)q)->d - ((abcc*)p)->d;
}

void heapup(int now)
{
	int parent;
	abcc tmp;
	parent = (now >> 1);
	if(parent)
	{
		if(heap[parent].p < heap[now].p)
		{
			tmp = heap[parent];
			heap[parent] = heap[now];
			heap[now] = tmp;
			heapup(parent);
		}
	}
}

void heapdown(int now)
{
	int left, right;
	abcc tmp;
	left = (now << 1);
	right = left + 1;
	if(left < h)
	{
		if(right >= h || heap[left].p > heap[right].p)
		{
			if(heap[left].p > heap[now].p)
			{
				tmp = heap[left];
				heap[left] = heap[now];
				heap[now] = tmp;
				heapdown(left);
			}
		}
		else
		{
			if(heap[right].p > heap[now].p)
			{
				tmp = heap[right];
				heap[right] = heap[now];
				heap[now] = tmp;
				heapdown(right);
			}
		}
	}
}

void push(abcc targ)
{
	heap[h++] = targ;
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
	int n, l, i, j, k, ans;
	while(scanf("%d%d", &n, &l) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &asdf[i].p, &asdf[i].d);
		}
		qsort(asdf, n, sizeof(asdf[0]), comp);
		for(i=asdf[0].d, ptr=asdf, ans=0, h=1; i>=0; i--)
		{
			for(; ptr-asdf<n&&ptr->d>=i; ptr++)
			{
				push(*ptr);
			}
			for(j=0; j<l&&pop(); j++)
			{
				ans += heap[0].p;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
