#include <stdio.h>
#include <string.h>

#define INF 2147483647

int hnum;
int speed[105];
int dis[105], used[105];
int heap[12005];
int map[10][105], ary[10][105], num[10];
char buf[2008];

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

void heapup(int now)
{
	int parent, temp;
	parent = (now >> 1);
	if(parent)
	{
		if(dis[heap[parent]] >= dis[heap[now]])
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
	int left, right, temp;
	left = (now << 1);
	right = left + 1;
	if(left < hnum)
	{
		if(right >= hnum || dis[heap[left]] < dis[heap[right]])
		{
			if(dis[heap[left]] < dis[heap[now]])
			{
				temp = heap[left];
				heap[left] = heap[now];
				heap[now] = temp;
				heapdown(left);
			}
		}
		else
		{
			if(dis[heap[right]] < dis[heap[now]])
			{
				temp = heap[right];
				heap[right] = heap[now];
				heap[now] = temp;
				heapdown(right);
			}
		}
	}
}

void push(int target)
{
	heap[hnum++] = target;
	heapup(hnum-1);
}

int pop()
{
	if(hnum == 1)
	{
		return -1;
	}
	heap[0] = heap[1];
	heap[1] = heap[--hnum];
	heapdown(1);
	return heap[0];
}

int main()
{
	int n, m, i, j, temp, ans, target;
	char *ptr;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &speed[i]);
		}
		gets(buf);
		memset(map, 0, sizeof(map));
		memset(num, 0, sizeof(num));
		for(i=0; i<n; i++)
		{
			gets(buf);
			ptr = strtok(buf, " ");
			num[i] = 0;
			do
			{
				sscanf(ptr, "%d", &temp);
				ary[i][num[i]++] = temp;
				map[i][temp] = 1;
			}while(ptr=strtok(NULL, " "));
		}
		if(!m)
		{
			printf("0\n");
			continue;
		}
		for(i=1; i<100; i++)
		{
			dis[i] = INF;
			used[i] = 0;
		}
		dis[0] = -60;
		used[0] = 0;
		heap[1] = 0;
		hnum = 2;
		ans = -1;
		while((temp=pop()) != -1)
		{
			if(!used[temp])
			{
				used[temp] = 1;
				if(temp == m)
				{
					ans = dis[m];
					break;
				}
				for(i=0; i<n; i++)
				{
					if(map[i][temp])
					{
						for(j=0; j<num[i]; j++)
						{
							target = ary[i][j];
							if(!used[target] && dis[temp] + ab(target-temp)*speed[i] + 60 < dis[target])
							{
								dis[target] = dis[temp] + ab(target-temp)*speed[i] + 60;
								push(target);
							}
						}
					}
				}
			}
		}
		if(ans == -1)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
