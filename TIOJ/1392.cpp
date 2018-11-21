#include <stdio.h>
#include <string.h>

int ary[105][105], dp[105][105], used[105][105], h;

typedef struct node
{
	int x, y, d;
}node;

node heap[100000];

int max(int p, int q)
{
	return p>q ? p : q;
}

void heapdown(int now)
{
	int left, right;
	node temp;
	left = (now << 1);
	right = left + 1;
	if(left < h)
	{
		if(right >= h || heap[left].d < heap[right].d)
		{
			if(heap[left].d < heap[now].d)
			{
				temp = heap[left];
				heap[left] = heap[now];
				heap[now] = temp;
				heapdown(left);
			}
		}
		else
		{
			if(heap[right].d < heap[now].d)
			{
				temp = heap[right];
				heap[right] = heap[now];
				heap[now] = temp;
				heapdown(right);
			}
		}
	}
}

void heapup(int now)
{
	int parent;
	node temp;
	parent = (now >> 1);
	if(parent)
	{
		if(heap[now].d < heap[parent].d)
		{
			temp = heap[now];
			heap[now] = heap[parent];
			heap[parent] = temp;
			heapup(parent);
		}
	}
}

void push(int x, int y, int d)
{
	heap[h++] = (node){x, y, d};
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

void check(int x, int y, int d)
{
	int temp;
	if((temp=max(ary[x][y], d)+1) < dp[x][y])
	{
		dp[x][y] = temp;
		push(x, y, temp);
	}
}

int main()
{
	int n, i, j, x, y, d, ans;
	node now;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<=i; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		h = 1;
		push(0, 0, ary[0][0]);
		memset(used, 0, sizeof(used));
		memset(dp, 1, sizeof(dp));
		dp[0][0] = ary[0][0];
		ans = -1;
		while(pop())
		{
			now = heap[0];
			x = now.x;
			y = now.y;
			d = now.d;
			/*printf("%d %d %d\n", x, y, d);*/
			if(d > ans)
			{
				ans = d;
			}
			if(used[x][y] == 0)
			{
				used[x][y] = 1;
				if(x)
				{
					if(y != x)
					{
						check(x-1, y, d);
					}
					if(y)
					{
						check(x-1, y-1, d);
					}
				}
				if(x < n-1)
				{
					check(x+1, y, d);
					check(x+1, y+1, d);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
