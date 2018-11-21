#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define N 32768

int h;
int heap[N], value[N], length[N], cut[N], ary[20];
char used[N];

struct point
{
	int x, y, v, l, n;
};

struct point p[20], ch[20];

int comp(const void *p, const void *q)
{
	if(((struct point*)p)->x != ((struct point*)q)->x)
	{
		return ((struct point*)p)->x - ((struct point*)q)->x;
	}
	return ((struct point*)p)->y - ((struct point*)q)->y;
}

int ncomp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int compare(int p, int q)
{
	if(value[p] != value[q])
	{
		return value[p] - value[q];
	}
	return cut[p] - cut[q];
}

double getdist(double x, double y)
{
	return sqrt(x*x+y*y);
}

int cross(struct point p, struct point q, struct point r)
{
	return (q.x-p.x) * (r.y-p.y) - (q.y-p.y) * (r.x-p.x);
}

void heapup(int now)
{
	int parent, temp;
	parent = (now>>1);
	if(parent)
	{
		if(compare(heap[parent], heap[now]) > 0)
		{
			temp = heap[now];
			heap[now] = heap[parent];
			heap[parent] = temp;
			heapup(parent);
		}
	}
}

void heapdown(int now)
{
	int left, right, temp;
	left = (now<<1);
	right = left + 1;
	if(left < h)
	{
		if(right >= h || compare(heap[left], heap[right]) < 0)
		{
			if(compare(heap[left], heap[now]) < 0)
			{
				temp = heap[now];
				heap[now] = heap[left];
				heap[left] = temp;
				heapdown(left);
			}
		}
		else
		{
			if(compare(heap[right], heap[now]) < 0)
			{
				temp = heap[now];
				heap[now] = heap[right];
				heap[right] = temp;
				heapdown(right);
			}
		}
	}
}

void push(int s)
{
	heap[h++] = s;
	heapup(h-1);
}

int pop()
{
	if(h == 1)
	{
		return -1;
	}
	heap[0] = heap[1];
	heap[1] = heap[--h];
	heapdown(1);
	return heap[0];
}

int main()
{
	int cas, n, m, i, j, k, s, v, l, c, temp;
	double need;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d%d", &p[i].x, &p[i].y, &p[i].v, &p[i].l);
			p[i].n = i + 1;
		}
		qsort(p, n, sizeof(struct point), comp);
		memset(used, 0, sizeof(used));
		heap[1] = (1<<n) - 1;
		h = 2;
		used[(1<<n)-1] = 1;
		value[(1<<n)-1] = 0;
		length[(1<<n)-1] = 0;
		cut[(1<<n)-1] = 0;
		while((temp=pop()) != -1)
		{
			s = temp;
			v = value[s];
			l = length[s];
			c = cut[s];
			for(i=0, m=0; i<n; i++)
			{
				if(s & (1<<i))
				{
					for(; m>=2&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
			}
			for(i=n-2, j=m+1; i>=0; i--)
			{
				if(s & (1<<i))
				{
					for(; m>=j&&cross(ch[m-2], ch[m-1], p[i])<=0; m--);
					ch[m++] = p[i];
				}
			}
			for(i=1, need=0.0; i<m; i++)
			{
				need += getdist(ch[i-1].x-ch[i].x, ch[i-1].y-ch[i].y);
				if(need > l)
				{
					break;
				}
			}
			if(need <= l)
			{
				if(cas)
				{
					printf("\n");
				}
				printf("Forest %d\n", ++cas);
				printf("Cut these trees:");
				for(i=0, m=0; i<n; i++)
				{
					if(!(s & (1<<i)))
					{
						ary[m++] = p[i].n;
					}
				}
				qsort(ary, m, sizeof(int), ncomp);
				for(i=0; i<m; i++)
				{
					printf(" %d", ary[i]);
				}
				printf("\n");
				printf("Extra wood: %.2lf\n", l-need);
				break;
			}
			for(i=0; i<n; i++)
			{
				if((s & (1<<i)) && !used[temp=(s-(1<<i))])
				{
					used[temp] = 1;
					value[temp] = v + p[i].v;
					length[temp] = l + p[i].l;
					cut[temp] = c + 1;
					push(temp);
				}
			}
		}
	}
	return 0;
}
