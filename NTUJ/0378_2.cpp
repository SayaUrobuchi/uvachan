#include <stdio.h>
#include <string.h>

int m1[1005], m2[1005], used[1005][105][105], h;

typedef struct node
{
	int next, m1, m2, ret;
}node;

node heap[5000000];

void heapup(int now)
{
	int parent;
	node temp;
	parent = (now>>1);
	if(parent)
	{
		if(heap[parent].ret > heap[now].ret)
		{
			temp = heap[parent];
			heap[parent] = heap[now];
			heap[now] = temp;
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
		if(right >= h || heap[left].ret < heap[right].ret)
		{
			if(heap[now].ret > heap[left].ret)
			{
				temp = heap[now];
				heap[now] = heap[left];
				heap[left] = temp;
				heapdown(left);
			}
		}
		else
		{
			if(heap[now].ret > heap[right].ret)
			{
				temp = heap[now];
				heap[now] = heap[right];
				heap[right] = temp;
				heapdown(right);
			}
		}
	}
}

void push(int next, int mm1, int mm2, int ret)
{
	heap[h++] = (node){next, mm1, mm2, ret};
	if(next == 6 && mm1 == 2 && mm2 == 2 && ret == 1) printf("123 %d\n", h-1);
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
	int n, m, k, i, j;
	node now;
	while(scanf("%d%d%d", &n, &m, &k) == 3)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<k; i++)
		{
			scanf("%d", &j);
			scanf("%d%d", &m1[j], &m2[j]);
		}
		h = 1;
		push(0, -1, -1, 0);
		memset(used, 1, sizeof(used));
		while(pop())
		{
			now = heap[0];
			printf("%d %d %d %d\n", now.next, now.m1, now.m2, now.ret);
			if(now.next == k)
			{
				break;
			}
			if(m1[now.next] > now.m1)
			{
				now.m1 = m1[now.next];
				if(used[now.next][now.m1][now.m2] > now.ret)
				{
					used[now.next][now.m1][now.m2] = now.ret;
					push(now.next+1, now.m1, now.m2, now.ret);
				}
			}
			else
			{
				now.m1 = m1[now.next];
				now.ret++;
				if(used[now.next][now.m1][now.m2] > now.ret)
				{
					used[now.next][now.m1][now.m2] = now.ret;
					push(now.next+1, now.m1, now.m2, now.ret);
				}
			}
			now = heap[0];
			if(m2[now.next] > now.m2)
			{
				now.m2 = m2[now.next];
				if(used[now.next][now.m1][now.m2] > now.ret)
				{
					used[now.next][now.m1][now.m2] = now.ret;
					push(now.next+1, now.m1, now.m2, now.ret);
				}
			}
			else
			{
				now.m2 = m2[now.next];
				now.ret++;
				if(used[now.next][now.m1][now.m2] > now.ret)
				{
					used[now.next][now.m1][now.m2] = now.ret;
					if(now.next == 5)printf("!!!%d %d %d %d\n", now.next+1, now.m1, now.m2, now.ret);
					push(now.next+1, now.m1, now.m2, now.ret);
				}
			}
		}
		printf("h %d\n", h);
		printf("%d\n", now.ret);
	}
	return 0;
}
