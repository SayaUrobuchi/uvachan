#include <stdio.h>
#include <string.h>

int len;
int map[10001][101], num[10000];
int length[10001][101];
int dis[10001];
int heap[100000];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

void swap(int *p, int *q)
{
	if(*p != *q)
	{
		*p ^= *q ^= *p ^= *q;
	}
}

void heapdown(int now)
{
	int left, right;
	left = now + now;
	right = left + 1;
	if(left < len)
	{
		if(right >= len || dis[heap[left]] < dis[heap[right]])
		{
			if(dis[heap[left]] < dis[heap[now]])
			{
				swap(heap+left, heap+now);
				heapdown(left);
			}
		}
		else
		{
			if(dis[heap[right]] < dis[heap[now]])
			{
				swap(heap+right, heap+now);
				heapdown(right);
			}
		}
	}
}

void heapup(int now)
{
	int parent;
	parent = now / 2;
	if(parent)
	{
		if(dis[heap[now]] < dis[heap[parent]])
		{
			swap(heap+now, heap+parent);
			heapup(parent);
		}
	}
}

void push(int now)
{
	heap[len++] = now;
	heapup(len-1);
}

void pop()
{
	heap[0] = heap[1];
	heap[1] = heap[--len];
	heapdown(1);
}

int main()
{
	int n, m, o, i, j, k, p, now, ans;
	k = 0;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		map[n][num[n]] = m;
		map[m][num[m]] = n;
		k = max(k, max(n, m));
		length[n][num[n]++] = o;
		length[m][num[m]++] = o;
	}
	for(i=1, ans=0; i<k; i++)
	{
		memset(dis, 1, sizeof(dis));
		dis[i] = 0;
		len = 1;
		for(j=0; j<num[i]; j++)
		{
			dis[map[i][j]] = length[i][j];
			push(map[i][j]);
		}
		for(j=1; j<k; )
		{
			pop();
			now = heap[0];
			if(dis[now])
			{
				j++;
				ans = max(dis[now], ans);
				for(p=0; p<num[now]; p++)
				{
					if(dis[map[now][p]] > dis[now] + length[now][p])
					{
						dis[map[now][p]] = dis[now] + length[now][p];
						push(map[now][p]);
					}
				}
				dis[now] = 0;
			}
		}
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
