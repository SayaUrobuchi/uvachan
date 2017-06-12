#include <stdio.h>
#include <string.h>

#define INF 2147483647

int hnum;
int dis[505], used[505], dist[505][505];
int map[505][25], num[505];
int heap[12005];
int fire[505], tbl[505];
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
		return 0;
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

int main()
{
	int count, n, m, i, j, l, f, p, q, temp, target, min;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		memset(fire, 0, sizeof(fire));
		for(i=0; i<m; i++)
		{
			scanf("%d", &f);
			fire[f] = 1;
		}
		memset(num, 0, sizeof(num));
		gets(buf);
		while(gets(buf))
		{
			if(!buf[0])
			{
				break;
			}
			sscanf(buf, "%d%d%d", &p, &q, &l);
			map[p][num[p]++] = q;
			map[q][num[q]++] = p;
			dist[p][q] = dist[q][p] = l;
		}
		memset(tbl, 0, sizeof(tbl));
		for(j=1; j<=n; j++)
		{
			dis[j] = INF;
			used[j] = 0;
		}
		for(i=1; i<=n; i++)
		{
			heap[1] = i;
			hnum = 2;
			dis[i] = 0;
			while(temp=pop())
			{
				if(!used[temp])
				{
					if(fire[temp])
					{
						f = dis[temp];
						break;
					}
					used[temp] = 1;
					for(j=0; j<num[temp]; j++)
					{
						target = map[temp][j];
						if(!used[target] && dis[temp] + dist[temp][target] < dis[target])
						{
							dis[target] = dis[temp] + dist[temp][target];
							push(target);
						}
					}
				}
			}
			for(j=1; j<=n; j++)
			{
				if(!used[j])
				{
					dis[j] = f;
				}
				/*printf("from %d to %d: %d\n", i, j, dis[j]);*/
				if(tbl[j] < dis[j])
				{
					tbl[j] = dis[j];
				}
				dis[j] = INF;
				used[j] = 0;
			}
		}
		for(j=1, min=INF; j<=n; j++)
		{
			if(tbl[j] < min)
			{
				min = tbl[j];
				temp = j;
			}
		}
		/*printf("XDDD %d\n", tbl[temp]);*/
		printf("%d\n", temp);
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
