#include <stdio.h>
#include <string.h>

int n, m, s, t, size, dislim;
int target[105][105];
int map[105][105];
int height[105][105];
int used[105][105];
int redx[55], redy[55];
int greenx[55], greeny[55];
int tx[105], ty[105];
int cap[105];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
int num[105];
int ary[105][105];
int sused[105], tused[105];

struct data
{
	int x, y, step, type;
};

struct data heap[10500];

int valid(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}

void heapup(int now)
{
	int parent;
	struct data temp;
	parent = now / 2;
	if(parent)
	{
		if(heap[now].step < heap[parent].step)
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
	struct data temp;
	left = now + now;
	right = left + 1;
	if(left < size)
	{
		if(right >= size || heap[left].step < heap[right].step)
		{
			if(heap[now].step > heap[left].step)
			{
				temp = heap[now];
				heap[now] = heap[left];
				heap[left] = temp;
				heapdown(left);
			}
		}
		else
		{
			if(heap[now].step > heap[right].step)
			{
				temp = heap[now];
				heap[now] = heap[right];
				heap[right] = temp;
				heapdown(right);
			}
		}
	}
}

struct data pop()
{
	if(size == 1)
	{
		heap[0].step = -1;
		return heap[0];
	}
	heap[0] = heap[1];
	heap[1] = heap[--size];
	heapdown(1);
	return heap[0];
}

void push(struct data now)
{
	heap[size++] = now;
	heapup(size-1);
}

int fill(int);

int assign(int now)
{
	int i;
	if(num[now] < cap[now])
	{
		return 1;
	}
	for(i=0; i<cap[now]; i++)
	{
		if(!sused[ary[now][i]])
		{
			if(fill(ary[now][i]))
			{
				ary[now][i] = ary[now][--num[now]];
				return 1;
			}
		}
	}
	return 0;
}

int fill(int now)
{
	int i;
	sused[now] = 1;
	for(i=1; i<=t; i++)
	{
		if(!tused[i] && map[now][i] <= dislim && num[i] < cap[i])
		{
			ary[i][num[i]++] = now;
			return 1;
		}
	}
	for(i=1; i<=t; i++)
	{
		if(!tused[i] && map[now][i] <= dislim)
		{
			tused[i] = 1;
			if(assign(i))
			{
				ary[i][num[i]++] = now;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int count, i, j, k, p, q, c, x, y, dx, dy, type, step, left, right, center, ans, goldx, goldy;
	struct data temp;
	scanf("%d", &count);
	while(count--)
	{
		memset(target, 0, sizeof(target));
		scanf("%d%d%d%d", &n, &m, &s, &t);
		for(i=1; i<=s; i++)
		{
			scanf("%d%d", &redx[i], &redy[i]);
		}
		for(i=1; i<=s; i++)
		{
			scanf("%d%d", &greenx[i], &greeny[i]);
		}
		scanf("%d%d", &goldx, &goldy);
		for(i=1; i<=t; i++)
		{
			scanf("%d%d%d", &tx[i], &ty[i], &cap[i]);
			target[tx[i]][ty[i]] = i;
		}
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=m; j++)
			{
				scanf("%d", &height[i][j]);
			}
		}
		for(i=1; i<=s; i++)
		{
			memset(used, 0, sizeof(used));
			temp.x = redx[i];
			temp.y = redy[i];
			temp.type = 1;
			temp.step = 0;
			size = 1;
			push(temp);
			used[redx[i]][redy[i]] = 1;
			for(; ; )
			{
				temp = pop();
				if(temp.step == -1)
				{
					break;
				}
				x = temp.x;
				y = temp.y;
				type = temp.type;
				step = temp.step;
				if(step + 1 != used[x][y])
				{
					continue;
				}
				if(target[x][y])
				{
					map[i][target[x][y]] = step;
				}
				for(k=0; k<4; k++)
				{
					dx = x + wayx[k];
					dy = y + wayy[k];
					if(valid(dx, dy))
					{
						temp.x = dx;
						temp.y = dy;
						if((type && height[x][y] > height[dx][dy]) || (!type && height[x][y] < height[dx][dy]))
						{
							temp.type = 1 - type;
							temp.step = step + 1;
						}
						else
						{
							temp.type = type;
							temp.step = step;
						}
						if(!used[dx][dy] || used[dx][dy] > temp.step + 1)
						{
							used[dx][dy] = temp.step + 1;
							push(temp);
						}
					}
				}
			}
		}
		for(i=1; i<=s; i++)
		{
			memset(used, 0, sizeof(used));
			temp.x = greenx[i];
			temp.y = greeny[i];
			temp.type = 0;
			temp.step = 0;
			size = 1;
			push(temp);
			used[greenx[i]][greeny[i]] = 1;
			for(; ; )
			{
				temp = pop();
				if(temp.step == -1)
				{
					break;
				}
				x = temp.x;
				y = temp.y;
				type = temp.type;
				step = temp.step;
				if(step + 1 != used[x][y])
				{
					continue;
				}
				if(target[x][y])
				{
					map[s+i][target[x][y]] = step;
				}
				for(k=0; k<4; k++)
				{
					dx = x + wayx[k];
					dy = y + wayy[k];
					if(valid(dx, dy))
					{
						temp.x = dx;
						temp.y = dy;
						if((type && height[x][y] > height[dx][dy]) || (!type && height[x][y] < height[dx][dy]))
						{
							temp.type = 1 - type;
							temp.step = step + 1;
						}
						else
						{
							temp.type = type;
							temp.step = step;
						}
						if(!used[dx][dy] || used[dx][dy] > temp.step + 1)
						{
							used[dx][dy] = temp.step + 1;
							push(temp);
						}
					}
				}
			}
		}
		s += s;
		/*for(i=1; i<=s; i++)
		{
			for(j=1; j<=t; j++)
			{
				printf("%d %d: %d\n", i, j, map[i][j]);
			}
		}*/
		for(left=0, right=100; left<=right; )
		{
			center = left + right;
			center /= 2;
			dislim = center;
			memset(num, 0, sizeof(num));
			for(i=1, c=0; i<=s&&c<s-center; i++)
			{
				memset(sused, 0, sizeof(sused));
				memset(tused, 0, sizeof(tused));
				c += fill(i);
			}
			if(c >= s-center)
			{
				ans = center;
				right = center - 1;
			}
			else
			{
				left = center + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
