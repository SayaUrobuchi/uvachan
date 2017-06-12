#include <stdio.h>

int n, m, s;

struct data
{
	int x, y;
};

struct data *heap[41000], *queue[41000], ary[82000], *temp;

int getnum(struct data *ptr)
{
	return (ptr->x) * (ptr->y) - 1;
}

void heapdown(int now)
{
	int left, right, lvalue, rvalue;
	left = now << 1;
	right = left + 1;
	if(left < s)
	{
		if(right >= s || (lvalue=getnum(heap[left])) > (rvalue=getnum(heap[right])))
		{
			if(getnum(heap[now]) < lvalue)
			{
				temp = heap[now];
				heap[now] = heap[left];
				heap[left] = temp;
				heapdown(left);
			}
		}
		else
		{
			if(getnum(heap[now]) < rvalue)
			{
				temp = heap[now];
				heap[now] = heap[right];
				heap[right] = temp;
				heapdown(right);
			}
		}
	}
}

void heapup(int now)
{
	int parent;
	parent = now >> 1;
	if(parent)
	{
		if(getnum(heap[now]) > getnum(heap[parent]))
		{
			temp = heap[now];
			heap[now] = heap[parent];
			heap[parent] = temp;
			heapup(parent);
		}
	}
}

struct data *pop()
{
	if(s == 1)
	{
		return NULL;
	}
	heap[0] = heap[1];
	heap[1] = heap[--s];
	heapdown(1);
	return heap[0];
}

void push(int x, int y)
{
	if(x > 1 || y > 1)
	{
		ary[n].x = x;
		ary[n].y = y;
		heap[s++] = ary + (n++);
		heapup(s-1);
	}
}

int main()
{
	int i, j, k, p, q;
	while(scanf("%d%d%d", &m, &p, &q) == 3)
	{
		if(!m && !p && !q)
		{
			break;
		}
		n = 0;
		s = 1;
		push(p, q);
		for(i=0; ; i++)
		{
			for(j=0; j<m&&(queue[j]=pop()); j++);
			/*printf("XD %d\n", j);*/
			if(!j)
			{
				break;
			}
			for(k=0; k<j; k++)
			{
				/*printf("%d %d\n", queue[k]->x, queue[k]->y);*/
				if((queue[k]->x) > 1)
				{
					push((queue[k]->x)>>1, queue[k]->y);
					push((queue[k]->x+1)>>1, queue[k]->y);
				}
				else
				{
					push(queue[k]->x, (queue[k]->y)>>1);
					push(queue[k]->x, (queue[k]->y+1)>>1);
				}
			}
		}
		printf("%d by %d takes %d cuts\n\n", p, q, i);
	}
	return 0;
}
