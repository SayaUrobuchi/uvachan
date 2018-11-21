#include <stdio.h>
#include <algorithm>

typedef struct heap
{
	int hn;
	int h[10005];
	bool (*cmp)(int p, int q);
}heap;

heap h1, h2;

bool min_heap(int p, int q)
{
	return q<p;
}

bool max_heap(int p, int q)
{
	return p<q;
}

void push(heap *h, int tar)
{
	h->h[h->hn++] = tar;
	std::push_heap(h->h, h->h+h->hn, h->cmp);
}

int pop(heap *h)
{
	int t;
	t = h->h[0];
	std::pop_heap(h->h, h->h+h->hn--, h->cmp);
	return t;
}

int main()
{
	int cc, n, t;
	h1.hn = 0;
	h2.hn = 0;
	h1.cmp = max_heap;
	h2.cmp = min_heap;
	cc = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!h1.hn || n <= h1.h[0])
		{
			push(&h1, n);
		}
		else
		{
			push(&h2, n);
		}
		if(h1.hn < h2.hn)
		{
			t = pop(&h2);
			push(&h1, t);
		}
		else if(h1.hn > h2.hn+1)
		{
			t = pop(&h1);
			push(&h2, t);
		}
		cc = (cc^1);
		if(cc)
		{
			printf("%d\n", h1.h[0]);
		}
		else
		{
			printf("%d\n", (h1.h[0]+h2.h[0])>>1);
		}
	}
	return 0;
}
