#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 2147483647

int hnum;
int index[105];
int maxtbl[1005][105], mintbl[1005][105];
int num[1005], dis[105], used[105];
int heap[12005];
char name[105][105];
char buf1[2008], buf2[1008];

struct data
{
	int time, loc;
};

struct data map[1005][105];

int comp(const void *p, const void *q)
{
	return strcmp(name[*(int*)p], name[*(int*)q]);
}

int scomp(const void *p, const void *q)
{
	return ((struct data*)p)->time - ((struct data*)q)->time;
}

int bisearch(char *s, int left, int right)
{
	int center, cmp;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center >>= 1;
	cmp = strcmp(name[index[center]], s);
	if(!cmp)
	{
		return index[center];
	}
	else if(cmp > 0)
	{
		return bisearch(s, left, center-1);
	}
	return bisearch(s, center+1, right);
}

void minheapup(int now)
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
			minheapup(parent);
		}
	}
}

void maxheapup(int now)
{
	int parent, temp;
	parent = (now >> 1);
	if(parent)
	{
		if(dis[heap[parent]] <= dis[heap[now]])
		{
			temp = heap[parent];
			heap[parent] = heap[now];
			heap[now] = temp;
			maxheapup(parent);
		}
	}
}

void minheapdown(int now)
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
				minheapdown(left);
			}
		}
		else
		{
			if(dis[heap[right]] < dis[heap[now]])
			{
				temp = heap[right];
				heap[right] = heap[now];
				heap[now] = temp;
				minheapdown(right);
			}
		}
	}
}

void maxheapdown(int now)
{
	int left, right, temp;
	left = (now << 1);
	right = left + 1;
	if(left < hnum)
	{
		if(right >= hnum || dis[heap[left]] > dis[heap[right]])
		{
			if(dis[heap[left]] > dis[heap[now]])
			{
				temp = heap[left];
				heap[left] = heap[now];
				heap[now] = temp;
				maxheapdown(left);
			}
		}
		else
		{
			if(dis[heap[right]] > dis[heap[now]])
			{
				temp = heap[right];
				heap[right] = heap[now];
				heap[now] = temp;
				maxheapdown(right);
			}
		}
	}
}

void minpush(int target)
{
	heap[hnum++] = target;
	minheapup(hnum-1);
}

void maxpush(int target)
{
	heap[hnum++] = target;
	maxheapup(hnum-1);
}

int minpop()
{
	if(hnum == 1)
	{
		return -1;
	}
	heap[0] = heap[1];
	heap[1] = heap[--hnum];
	minheapdown(1);
	return heap[0];
}

int maxpop()
{
	if(hnum == 1)
	{
		return -1;
	}
	heap[0] = heap[1];
	heap[1] = heap[--hnum];
	maxheapdown(1);
	return heap[0];
}

int main()
{
	int cas, count, n, m, i, j, target, start, destination, stime, temp, arrive;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", name[i]);
			index[i] = i;
		}
		qsort(index, n, sizeof(int), comp);
		memset(maxtbl, -1, sizeof(maxtbl));
		memset(mintbl, 1, sizeof(mintbl));
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d", &num[i]);
			for(j=0; j<num[i]; j++)
			{
				scanf("%d%s", &map[i][j].time, buf1);
				target = bisearch(buf1, 0, n-1);
				map[i][j].loc = target;
				if(target != -1)
				{
					if(map[i][j].time > maxtbl[i][target])
					{
						maxtbl[i][target] = map[i][j].time;
					}
					if(map[i][j].time < mintbl[i][target])
					{
						mintbl[i][target] = map[i][j].time;
					}
				}
			}
			/* In fact, the given list is sorted.. */
			qsort(map[i], num[i], sizeof(struct data), scomp);
		}
		scanf("%d%s%s", &stime, buf1, buf2);
		printf("Scenario %d\n", ++cas);
		start = bisearch(buf1, 0, n-1);
		destination = bisearch(buf2, 0, n-1);
		if(start == -1 || destination == -1)
		{
			printf("No connection\n\n");
			continue;
		}
		for(i=0; i<n; i++)
		{
			dis[i] = INF;
		}
		memset(used, 0, sizeof(used));
		dis[start] = stime;
		heap[1] = start;
		hnum = 2;
		while((temp=minpop()) != -1)
		{
			if(!used[temp])
			{
				used[temp] = 1;
				if(temp == destination)
				{
					break;
				}
				for(i=0; i<m; i++)
				{
					if(maxtbl[i][temp] >= dis[temp])
					{
						for(j=0; j<num[i]; j++)
						{
							if(map[i][j].time >= dis[temp] && map[i][j].loc == temp)
							{
								break;
							}
						}
						for(j++; j<num[i]; j++)
						{
							if((map[i][j].loc != -1 && !used[map[i][j].loc]) && dis[map[i][j].loc] > map[i][j].time)
							{
								dis[map[i][j].loc] = map[i][j].time;
								minpush(map[i][j].loc);
							}
						}
					}
				}
			}
		}
		if(used[destination])
		{
			arrive = dis[destination];
			memset(used, 0, sizeof(used));
			memset(dis, -1, sizeof(dis));
			dis[destination] = arrive;
			heap[1] = destination;
			hnum = 2;
			while((temp=maxpop()) != -1)
			{
				if(!used[temp])
				{
					used[temp] = 1;
					if(temp == start)
					{
						break;
					}
					for(i=0; i<m; i++)
					{
						if(mintbl[i][temp] <= dis[temp])
						{
							for(j=num[i]-1; j>=0; j--)
							{
								if(map[i][j].time <= dis[temp] && map[i][j].loc == temp)
								{
									break;
								}
							}
							for(j--; j>=0; j--)
							{
								if((map[i][j].loc != -1 && !used[map[i][j].loc]) && dis[map[i][j].loc] < map[i][j].time)
								{
									dis[map[i][j].loc] = map[i][j].time;
									maxpush(map[i][j].loc);
								}
							}
						}
					}
				}
			}
			printf("Departure %04d %s\n", dis[start], buf1);
			printf("Arrival   %04d %s\n\n", arrive, buf2);
		}
		else
		{
			printf("No connection\n\n");
		}
	}
	return 0;
}
