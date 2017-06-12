#include <stdio.h>
#include <string.h>

#define INF 2147483647

int hnum;
int ary[55][105], map[55][105], num[55];
int dis[105], used[105], speed[55];
int heap[102005];
char buf[2008];

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

void push(int target)
{
	heap[hnum++] = target;
	heapup(hnum-1);
}

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int getdis(int e, int f)
{
	if(ary[e][num[e]-1] - f > f - ary[e][0])
	{
		return (ary[e][num[e]-1]-f) * speed[e];
	}
	return (f-ary[e][0]) * speed[e];
}

int main()
{
	int n, m, i, j, f, c, ans, temp;
	char *ptr;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &speed[i]);
		}
		gets(buf);
		memset(num, 0, sizeof(num));
		memset(map, 0, sizeof(map));
		for(i=0; i<n; i++)
		{
			gets(buf);
			ptr = strtok(buf, " ");
			do
			{
				sscanf(ptr, "%d", &j);
				map[i][j] = 1;
				ary[i][num[i]++] = j;
			}while(ptr=strtok(NULL, " "));
		}
		if(m == 0)
		{
			printf("0\n");
			continue;
		}
		for(i=1; i<100; i++)
		{
			dis[i] = INF;
			used[i] = 0;
		}
		dis[0] = used[0] = 0;
		heap[1] = 0;
		hnum = 2;
		ans = -1;
		while((temp=pop()) != -1)
		{
			/*printf("%d %d\n", temp, dis[temp]);*/
			if(!used[temp])
			{
				used[temp] = 1;
				if(temp == m)
				{
					ans = dis[temp];
					break;
				}
				for(i=0; i<n; i++)
				{
					if(map[i][temp])
					{
						for(j=0; j<num[i]; j++)
						{
							f = ary[i][j];
							if(!used[f] && dis[temp] + (c=getdis(i, temp)) + 5 + (ab(f-temp)*speed[i]) < dis[f])
							{
								dis[f] = dis[temp] + c + 5 + (ab(f-temp)*speed[i]);
								push(f);
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
			printf("%d\n", ans-5);
		}
	}
	return 0;
}
