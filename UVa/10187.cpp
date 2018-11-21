#include <stdio.h>
#include <string.h>

#define N 105
#define INF 2147483647

int n, hnum;
int heap[12005];
int dis[N], used[N];
int map[N][N], num[N], start[N][N], arrive[N][N];
char buf1[2008], buf2[2008];
char name[N][35];

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

int getindex(char *s)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(!strcmp(s, name[i]))
		{
			return i;
		}
	}
	strcpy(name[n++], s);
	return i;
}

int main()
{
	int cas, count, m, i, s, a, n1, n2, temp, hour, day, target, stime, atime;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &m);
		n = 0;
		memset(num, 0, sizeof(num));
		while(m--)
		{
			scanf("%s%s%d%d", buf1, buf2, &s, &a);
			if(s >= 18 || s <= 6)
			{
				if(s <= 6)
				{
					s += 24;
				}
				a += s;
				if(a <= 30)
				{
					n1 = getindex(buf1);
					n2 = getindex(buf2);
					map[n1][num[n1]] = n2;
					start[n1][num[n1]] = s;
					arrive[n1][num[n1]++] = a;
				}
			}
		}
		scanf("%s%s", buf1, buf2);
		s = getindex(buf1);
		a = getindex(buf2);
		heap[1] = s;
		hnum = 2;
		for(i=0; i<n; i++)
		{
			dis[i] = INF;
		}
		dis[s] = 0;
		memset(used, 0, sizeof(used));
		while((temp=pop()) != -1)
		{
			if(!used[temp])
			{
				used[temp] = 1;
				if(temp == a)
				{
					break;
				}
				hour = dis[temp] % 100;
				day = dis[temp] / 100;
				for(i=0; i<num[temp]; i++)
				{
					target = map[temp][i];
					stime = start[temp][i];
					atime = arrive[temp][i];
					if(stime >= hour)
					{
						if(dis[target] > day * 100 + atime)
						{
							dis[target] = day * 100 + atime;
							push(target);
						}
					}
					else
					{
						if(dis[target] > (day+1) * 100 + atime)
						{
							dis[target] = (day+1) * 100 + atime;
							push(target);
						}
					}
				}
			}
		}
		printf("Test Case %d.\n", ++cas);
		if(used[a])
		{
			printf("Vladimir needs %d litre(s) of blood.\n", dis[a]/100);
		}
		else
		{
			printf("There is no route Vladimir can take.\n");
		}
	}
	return 0;
}
