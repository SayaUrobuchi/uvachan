#include <stdio.h>
#include <string.h>

int h, ary[30];
char str[30][101], *sptr[128], buf[2008];

typedef struct data
{
	int f;
	char s[101];
}data;

data heap[101];

int comp(data p, data q)
{
	if(p.f != q.f)
	{
		return p.f - q.f;
	}
	return strcmp(p.s, q.s);
}

void heapup(int now)
{
	int parent;
	data temp;
	parent = (now>>1);
	if(parent)
	{
		if(comp(heap[now], heap[parent]) < 0)
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
	int left, right;
	data temp;
	left = (now<<1);
	right = left + 1;
	if(left < h)
	{
		if(right >= h || comp(heap[left], heap[right]) < 0)
		{
			if(comp(heap[left], heap[now]) < 0)
			{
				temp = heap[left];
				heap[left] = heap[now];
				heap[now] = temp;
				heapdown(left);
			}
		}
		else
		{
			if(comp(heap[right], heap[now]) < 0)
			{
				temp = heap[right];
				heap[right] = heap[now];
				heap[now] = temp;
				heapdown(right);
			}
		}
	}
}

data pop()
{
	heap[0] = heap[1];
	heap[1] = heap[--h];
	heapdown(1);
	return heap[0];
}

void push(char *s, int f)
{
	strcpy(heap[h].s, s);
	heap[h++].f = f;
	heapup(h-1);
}

int main()
{
	int cas, n, m, i, j, f, total, sum;
	char *p, *t, *ptr;
	data temp;
	cas = 0;
	while(scanf("%d", &m) == 1)
	{
		if(!m)
		{
			break;
		}
		scanf("%d", &n);
		for(i=1, total=0; i<=n; i++)
		{
			scanf("%d", &heap[i].f);
			total += heap[i].f;
			ary[i] = heap[i].f;
			heap[i].s[0] = i + 64;
			heap[i].s[1] = 0;
			sptr[i+64] = str[i];
		}
		sptr['a'] = str[0];
		for(h=n+1; (h-1-m)%(m-1); h++)
		{
			heap[h].f = 0;
			heap[h].s[0] = 'a';
			heap[h].s[1] = 0;
		}
		for(i=h-1; i>=1; i--)
		{
			heapdown(i);
		}
		for(; h-1>=m; )
		{
			for(i=0, p=buf, f=0; i<m; i++)
			{
				temp = pop();
				f += temp.f;
				t = p;
				for(ptr=temp.s; *ptr; ptr++)
				{
					*(sptr[*ptr]++) = i+48;
					*(p++) = *ptr;
				}
				if(*t < *buf)
				{
					j = *t;
					*t = *buf;
					*buf = j;
				}
			}
			*p = 0;
			push(buf, f);
		}
		for(i=1, sum=0; i<=n; i++)
		{
			*sptr[i+64] = 0;
			sum += ary[i] * strlen(str[i]);
		}
		printf("Set %d; average length %.2lf\n", ++cas, (double)sum/total);
		for(i=1; i<=n; i++)
		{
			printf("    %c: ", i+64);
			for(j=strlen(ptr=str[i])-1; j>=0; j--)
			{
				printf("%c", ptr[j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
