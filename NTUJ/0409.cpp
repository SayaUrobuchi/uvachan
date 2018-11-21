#include <stdio.h>
#include <string.h>

int num[5005], map[5005][5005], dd[5005][5005], used[5005], fdis[5005], sdis[5005], h;

typedef struct abc
{
	int n, d;
}nod;

nod heap[100000];

void heapdown(int now)
{
	int left, right;
	nod tmp;
	left = (now << 1);
	right = left + 1;
	if(left < h)
	{
		if(right >= h || heap[left].d < heap[right].d)
		{
			if(heap[left].d < heap[now].d)
			{
				tmp = heap[now];
				heap[now] = heap[left];
				heap[left] = tmp;
				heapdown(left);
			}
		}
		else
		{
			if(heap[right].d < heap[now].d)
			{
				tmp = heap[now];
				heap[now] = heap[right];
				heap[right] = tmp;
				heapdown(right);
			}
		}
	}
}

void heapup(int now)
{
	int parent;
	nod tmp;
	parent = (now >> 1);
	if(parent)
	{
		if(heap[now].d < heap[parent].d)
		{
			tmp = heap[now];
			heap[now] = heap[parent];
			heap[parent] = tmp;
			heapup(parent);
		}
	}
}

int pop()
{
	if(h == 1)
	{
		return 0;
	}
	heap[0] = heap[1];
	heap[1] = heap[--h];
	heapdown(1);
	return 1;
}

void push(int targ, int d)
{
	heap[h++] = (nod){targ, d};
	heapup(h-1);
}

int main()
{
	int n, m, i, j, k, d, id, td, targ;
	nod node;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(num, 0, sizeof(num));
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			i--;
			j--;
			map[i][num[i]] = j;
			map[j][num[j]] = i;
			dd[i][num[i]++] = dd[j][num[j]++] = k;
		}
		for(i=0; i<n; i++)
		{
			fdis[i] = 1000000000;
			sdis[i] = 1000000000;
		}
		memset(used, 0, sizeof(used));
		h = 1;
		push(0, 0);
		while(pop())
		{
			node = heap[0];
			if(used[id=node.n] > 1)
			{
				continue;
			}
			if(id == n-1 && used[id])
			{
				break;
			}
			used[id]++;
			for(i=0, d=node.d; i<num[id]; i++)
			{
				td = d + dd[id][i];
				targ = map[id][i];
				if(td < fdis[targ])
				{
					sdis[targ] = fdis[targ];
					fdis[targ] = td;
					push(targ, td);
					push(targ, sdis[targ]);
				}
				else if(td > fdis[targ] && td < sdis[targ])
				{
					sdis[targ] = td;
					push(targ, td);
				}
			}
		}
		printf("%d\n", sdis[n-1]);
	}
	return 0;
}
