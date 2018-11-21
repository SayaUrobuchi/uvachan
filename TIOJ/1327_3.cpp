#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int h, dis[100005], px[100005], py[100005], used[100005], xo[100005], yo[100005], con[100005][4];

typedef struct hnode
{
	int id, dis;
}hnode;

hnode heap[1000005];

int xcomp(const void *p, const void *q)
{
	return px[*(int*)p]==px[*(int*)q]?py[*(int*)p]-py[*(int*)q]:px[*(int*)p]-px[*(int*)q];
}

int ycomp(const void *p, const void *q)
{
	return py[*(int*)p]==py[*(int*)q]?px[*(int*)p]-px[*(int*)q]:py[*(int*)p]-py[*(int*)q];
}

int ab(int now)
{
	return now < 0 ? -now : now;
}

int getdis(int p, int q)
{
	return (px[p]==px[q] || py[p]==py[q]) ? ab(px[p]-px[q])+ab(py[p]-py[q]) : 2147483647;
}

int comp(hnode p, hnode q)
{
	return p.dis - q.dis;
}

void swap(hnode *p, hnode *q)
{
	hnode temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void heapup(int now)
{
	int parent;
	parent = (now >> 1);
	if(parent)
	{
		if(comp(heap[parent], heap[now]) > 0)
		{
			swap(heap+parent, heap+now);
			heapup(parent);
		}
	}
}

void heapdown(int now)
{
	int left, right;
	left = now + now;
	right = left + 1;
	if(left < h)
	{
		if(right >= h || comp(heap[left], heap[right]) < 0)
		{
			if(comp(heap[left], heap[now]) < 0)
			{
				swap(heap+left, heap+now);
				heapdown(left);
			}
		}
		else
		{
			if(comp(heap[right], heap[now]) < 0)
			{
				swap(heap+right, heap+now);
				heapdown(right);
			}
		}
	}
}

void push(int id, int dis)
{
	heap[h++] = (hnode){id, dis};
	heapup(h-1);
}

hnode pop()
{
	if(h == 1)
	{
		heap[0].id = -1;
		return heap[0];
	}
	heap[0] = heap[1];
	heap[1] = heap[--h];
	heapdown(1);
	return heap[0];
}

int main()
{
	int count, n, i, j, min;
	hnode temp;
	long long res;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			xo[i] = i;
			yo[i] = i;
		}
		qsort(xo, n, sizeof(int), xcomp);
		qsort(yo, n, sizeof(int), ycomp);
		for(i=0; i<n; i++)
		{
			/*printf("XO %d: %d %d\n", i, px[xo[i]], py[xo[i]]);
			printf("YO %d: %d %d\n", i, px[yo[i]], py[yo[i]]);*/
			if(i == 0 || px[xo[i]] != px[xo[i-1]])
			{
				con[xo[i]][0] = -1;
			}
			else
			{
				con[xo[i]][0] = xo[i-1];
			}
			if(i+1 >= n || px[xo[i]] != px[xo[i+1]])
			{
				con[xo[i]][1] = -1;
			}
			else
			{
				con[xo[i]][1] = xo[i+1];
			}
			if(i == 0 || py[yo[i]] != py[yo[i-1]])
			{
				con[yo[i]][2] = -1;
			}
			else
			{
				con[yo[i]][2] = yo[i-1];
			}
			if(i+1 >= n || py[yo[i]] != py[yo[i+1]])
			{
				con[yo[i]][3] = -1;
			}
			else
			{
				con[yo[i]][3] = yo[i+1];
			}
		}
		memset(used, 0, sizeof(used));
		h = 1;
		used[0] = 1;
		for(i=1; i<n; i++)
		{
			dis[i] = getdis(0, i);
			if(dis[i] != 2147483647)
			{
				push(i, dis[i]);
			}
		}
		res = 0;
		while((temp=pop()).id != -1)
		{
			if(used[temp.id])
			{
				continue;
			}
			/*printf("XDDD %d %d\n", temp.id, temp.dis);*/
			used[temp.id] = 1;
			res += temp.dis;
			for(j=0; j<4; j++)
			{
				/*printf("con %d %d = %d\n", temp.id, j, con[temp.id][j]);*/
				if((i=con[temp.id][j]) != -1)
				{
					if(used[i] == 0 && (min=getdis(i, temp.id)) < dis[i])
					{
						dis[i] = min;
						push(i, dis[i]);
					}
				}
			}
		}
		printf("%I64d\n", res);
	}
	return 0;
}
