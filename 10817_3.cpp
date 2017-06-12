#include <stdio.h>
#include <string.h>

int n, len;
int subject[9];
int ability[101][9];
int price[101];
int state[101][6561];
char str[10000];

struct data
{
	int price;
	int state;
	int limit;
};

struct data temp;
struct data heap[650000];

int decode()
{
	int i, j, result;
	for(i=1, j=1, result=0; i<=n; i++, j*=3)
	{
		if(subject[i] > 0)
		{
			result += subject[i] * j;
		}
	}
	return result;
}

void encode(int now)
{
	int i;
	for(i=1; i<=n; i++, now/=3)
	{
		subject[i] = now % 3;
	}
}

void heapdown(int now)
{
	int left, right;
	left = now + now;
	right = left + 1;
	if(left >= len)
	{
		return;
	}
	if(right >= len || heap[left].price < heap[right].price)
	{
		if(heap[now].price > heap[left].price)
		{
			temp = heap[now];
			heap[now] = heap[left];
			heap[left] = temp;
			heapdown(left);
		}
	}
	else
	{
		if(heap[now].price > heap[right].price)
		{
			temp = heap[now];
			heap[now] = heap[right];
			heap[right] = temp;
			heapdown(right);
		}
	}
}

void heapup(int now)
{
	int parent;
	if(now == 1)
	{
		return;
	}
	parent = now / 2;
	if(heap[now].price < heap[parent].price)
	{
		temp = heap[now];
		heap[now] = heap[parent];
		heap[parent] = temp;
		heapup(parent);
	}
}

int pop()
{
	if(len == 1)
	{
		return 0;
	}
	heap[0] = heap[1];
	heap[1] = heap[--len];
	heapdown(1);
	return 1;
}

void push(int s, int l, int p)
{
	heap[len].state = s;
	heap[len].limit = l;
	heap[len++].price = p;
	heapup(len-1);
}

int main()
{
	int m, o, i, j, p, total, tmp, optians;
	char *ptr;
	while(scanf("%d%d%d", &n, &o, &m) == 3)
	{
		if(!n)
		{
			break;
		}
		for(i=1; i<=n; i++)
		{
			subject[i] = 2;
		}
		total = 0;
		/*gets(str);*/
		while(o--)
		{
			memset(ability[0], 0, sizeof(ability[0]));
			/*gets(str);
			ptr = strtok(str, " ");
			sscanf(ptr, "%d", &p);
			total += p;
			while(ptr=strtok(NULL, " "))
			{
				sscanf(ptr, "%d", &p);
				ability[0][p] = 1;
			}*/
			scanf("%d", &p);
			total += p;
			gets(str);
			for(i=0; str[i]; i++)
			{
				if(str[i] != ' ')
				{
					ability[0][str[i]-48] = 1;
				}
			}
			for(j=1; j<=n; j++)
			{
				subject[j] -= ability[0][j];
			}
		}
		memset(ability, 0, sizeof(ability));
		for(i=0; i<m; i++)
		{
			/*gets(str);
			ptr = strtok(str, " ");
			sscanf(ptr, "%d", &price[i]);
			while(ptr=strtok(NULL, " "))
			{
				sscanf(ptr, "%d", &p);
				ability[i][p] = 1;
			}*/
			scanf("%d", &price[i]);
			gets(str);
			for(j=0; str[j]; j++)
			{
				if(str[j] != ' ')
				{
					ability[i][str[j]-48] = 1;
				}
			}
		}
		memset(state, 10, sizeof(state));
		len = 1;
		push(tmp=decode(), 0, total);
		state[0][tmp] = total;
		optians = 2147483640;
		while(pop())
		{
			if(heap[0].price == state[heap[0].limit][heap[0].state])
			{
				if(!heap[0].state)
				{
					optians = heap[0].price;
					break;
				}
				for(i=heap[0].limit; i<m; i++)
				{
					encode(heap[0].state);
					for(j=1; j<=n; j++)
					{
						subject[j] -= ability[i][j];
					}
					if(heap[0].price+price[i] < state[i+1][tmp=decode()])
					{
						state[i+1][tmp] = heap[0].price+price[i];
						push(tmp, i+1, heap[0].price+price[i]);
					}
				}
			}
		}
		printf("%d\n", optians);
	}
	return 0;
}
