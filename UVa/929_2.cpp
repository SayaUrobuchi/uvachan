#include <stdio.h>
#include <string.h>

int n, m, len, st, nx, ny, lx, ly, rx, ry;
char map[1000][1000];
int dis[1000][1000];
int heapx[600000], heapy[600000];
int wayx[4] = {0, 1, 0, -1};
int wayy[4] = {1, 0, -1, 0};
char str[5000];

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

void swap(int *p, int *q)
{
	st = *p;
	*p = *q;
	*q = st;
}

void heapdown(int now)
{
	int left, right;
	left = now + now;
	right = left + 1;
	if(left >= len)
	{
		return;
	}
	for(; left<len; left=now+now, right=left+1)
	{
		nx = heapx[now];
		ny = heapy[now];
		lx = heapx[left];
		ly = heapy[left];
		rx = heapx[right];
		ry = heapy[right];
		if(right >= len || dis[lx][ly] < dis[rx][ry])
		{
			if(dis[nx][ny] > dis[lx][ly])
			{
				swap(heapx+now, heapx+left);
				swap(heapy+now, heapy+left);
				now = left;
			}
			else
			{
				return;
			}
		}
		else
		{
			if(dis[nx][ny] > dis[rx][ry])
			{
				swap(heapx+now, heapx+right);
				swap(heapy+now, heapy+right);
				now = right;
			}
			else
			{
				return;
			}
		}
	}
}

void heapup(int now)
{
	int temp;
	temp = now / 2;
	if(!temp)
	{
		return;
	}
	for(; temp; temp=now/2)
	{
		nx = heapx[now];
		ny = heapy[now];
		lx = heapx[temp];
		ly = heapy[temp];
		if(dis[nx][ny] < dis[lx][ly])
		{
			swap(heapx+now, heapx+temp);
			swap(heapy+now, heapy+temp);
			now = temp;
		}
		else
		{
			return;
		}
	}
}

void push(int x, int y, int value)
{
	dis[x][y] = value;
	heapx[len] = x;
	heapy[len] = y;
	heapup(len++);
}

int pop()
{
	if(len == 1)
	{
		return 0;
	}
	heapx[0] = heapx[1];
	heapy[0] = heapy[1];
	heapx[1] = heapx[--len];
	heapy[1] = heapy[len];
	heapdown(1);
	return 1;
}

int main()
{
	int count, i, j, k, v, x, y, tx, ty;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		gets(str);
		for(i=0; i<n; i++)
		{
			gets(str);
			for(j=0, k=0; j<m; j++, k+=2)
			{
				map[i][j] = str[k] - 48;
				dis[i][j] = 2147483647;
			}
		}
		len = 1;
		push(0, 0, map[0][0]);
		for(; pop(); )
		{
			x = heapx[0];
			y = heapy[0];
			if(x == n-1 && y == m-1)
			{
				break;
			}
			if(dis[x][y] != -1)
			{
				for(k=0; k<4; k++)
				{
					tx = x + wayx[k];
					ty = y + wayy[k];
					if(valid(tx, ty))
					{
						if(dis[tx][ty] > dis[x][y] + map[tx][ty])
						{
							push(tx, ty, dis[x][y]+map[tx][ty]);
						}
					}
				}
				dis[x][y] = -1;
			}
		}
		printf("%d\n", dis[x][y]);
	}
	return 0;
}
