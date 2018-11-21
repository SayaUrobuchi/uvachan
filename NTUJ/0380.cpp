#include <stdio.h>
#include <string.h>

int from[155][505], fromt[155][505], num[155], map[155][155], sp[155][155], len[155][155];
int used[155][505], f, h;
double time[155][505];

typedef struct node
{
	int n, sp;
	double t;
}node;

node heap[1000000];

void backtracking(int now, int sp)
{
	if(now != 0)
	{
		backtracking(from[now][sp], fromt[now][sp]);
	}
	if(f)
	{
		printf(" ");
	}
	f = 1;
	printf("%d", now);
}

void heapup(int now)
{
	int parent;
	node temp;
	if(parent = (now>>1))
	{
		if(heap[parent].t > heap[now].t)
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
	left = (now << 1);
	right = left + 1;
	if(left < h)
	{
		if(right >= h || heap[left].t < heap[right].t)
		{
			if(heap[now].t > heap[left].t)
			{
				temp = heap[now];
				heap[now] = heap[left];
				heap[left] = temp;
				heapdown(left);
			}
		}
		else
		{
			if(heap[now].t > heap[right].t)
			{
				temp = heap[now];
				heap[now] = heap[right];
				heap[right] = temp;
				heapdown(right);
			}
		}
	}
}

void push(int n, int sp, double t)
{
	heap[h++] = (node){n, sp, t};
	heapup(h-1);
}

node* pop()
{
	if(h == 1)
	{
		return NULL;
	}
	heap[0] = heap[1];
	heap[1] = heap[--h];
	heapdown(1);
	return &heap[0];
}

int main()
{
	int n, m, i, j, v, l, t, next;
	node *ptr, now;
	while(scanf("%d%d%d", &n, &m, &t) == 3)
	{
		memset(num, 0, sizeof(num));
		while(m--)
		{
			scanf("%d%d%d%d", &i, &j, &v, &l);
			map[i][num[i]] = j;
			sp[i][num[i]] = v;
			len[i][num[i]++] = l;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<501; j++)
			{
				time[i][j] = (1ll << 50);
			}
		}
		memset(used, 0, sizeof(used));
		time[0][70] = 0;
		h = 1;
		push(0, 70, 0);
		while(ptr=pop())
		{
			now = *ptr;
			if(used[now.n][now.sp] == 0)
			{
				used[now.n][now.sp] = 1;
				if(now.n == t)
				{
					break;
				}
				for(i=0; i<num[now.n]; i++)
				{
					next = map[now.n][i];
					v = sp[now.n][i];
					if(v == 0)
					{
						v = now.sp;
					}
					l = len[now.n][i];
					if(used[next][v] == 0 && time[next][v] > time[now.n][now.sp] + (double)l / v)
					{
						time[next][v] = time[now.n][now.sp] + (double)l / v;
						from[next][v] = now.n;
						fromt[next][v] = now.sp;
						push(next, v, time[next][v]);
					}
				}
			}
		}
		f = 0;
		backtracking(now.n, now.sp);
		printf("\n");
	}
	return 0;
}
