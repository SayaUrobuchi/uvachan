#include <stdio.h>
#include <math.h>

int ary[1000][2], heap[1000000], num;
double dis[1000], heap2[1000000];

double calc(int x1, int y1, int x2, int y2)
{
	int xtmp, ytmp;
	xtmp = x1 - x2;
	ytmp = y1 - y2;
	return sqrt(xtmp * xtmp + ytmp * ytmp);
}

void heapup(int now)
{
	int tmp, tmp2;
	double tmp3;
	tmp = now / 2;
	if(!tmp)
	{
		return;
	}
	if(heap2[tmp] > heap2[now])
	{
		tmp3 = heap2[now];
		heap2[now] = heap2[tmp];
		heap2[tmp] = tmp3;
		tmp2 = heap[now];
		heap[now] = heap[tmp];
		heap[tmp] = tmp2;
		heapup(tmp);
	}
}

void heapdown(int now)
{
	int left, right, tmp;
	double tmp2;
	left = now * 2;
	if(left < num)
	{
		right = left + 1;
		if(right < num)
		{
			if(heap2[left] > heap2[right])
			{
				if(heap2[now] > heap2[right])
				{
					tmp2 = heap2[now];
					heap2[now] = heap2[right];
					heap2[right] = tmp2;
					tmp = heap[now];
					heap[now] = heap[right];
					heap[right] = tmp;
					heapdown(right);
				}
			}
			else
			{
				if(heap2[now] > heap2[left])
				{
					tmp2 = heap2[now];
					heap2[now] = heap2[left];
					heap2[left] = tmp2;
					tmp = heap[now];
					heap[now] = heap[left];
					heap[left] = tmp;
					heapdown(left);
				}
			}
		}
		else
		{
			if(heap2[now] > heap2[left])
			{
				tmp2 = heap2[now];
				heap2[now] = heap2[left];
				heap2[left] = tmp2;
				tmp = heap[now];
				heap[now] = heap[left];
				heap[left] = tmp;
				heapdown(left);
			}
		}
	}
}

void pop()
{
	heap[0] = heap[1];
	heap2[0] = heap2[1];
	heap[1] = heap[--num];
	heap2[1] = heap2[num];
	heapdown(1);
}

void push(int now, double dist)
{
	heap[num] = now;
	heap2[num] = dist;
	heapup(num++);
}

int main()
{
	int cas, count, n, m, i, j, c, l;
	double road, rail, temp, d;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		num = 1;
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i][0], &ary[i][1]);
			dis[i] = calc(ary[i][0], ary[i][1], ary[0][0], ary[0][1]);
			push(i, dis[i]);
		}
		dis[0] = -1;
		c = 1;
		road = rail = 0;
		for(i=1; i<n; i++)
		{
			pop();
			while(dis[heap[0]] < 0)
			{
				pop();
			}
			l = heap[0];
			d = heap2[0];
			dis[l] = -1;
			if(d > m)
			{
				c++;
				rail += d;
			}
			else
			{
				road += d;
			}
			for(j=1; j<n; j++)
			{
				if(dis[j] >= 0)
				{
					temp = calc(ary[l][0], ary[l][1], ary[j][0], ary[j][1]);
					if(temp < dis[j])
					{
						dis[j] = temp;
						push(j, temp);
					}
				}
			}
		}
		printf("Case #%d: %d %.0f %.0f\n", ++cas, c, road, rail);
	}
	return 0;
}
