#include <stdio.h>

int hn;
int heap[4096], now[4096], id[4096], tt[4096];
char s[1048576];

int comp(int p, int q)
{
	if (now[p] != now[q])
	{
		return now[p] - now[q];
	}
	return id[p] - id[q];
}

void heapdown(int t)
{
	int left, right, temp;
	while ((left=(t<<1)) <= hn)
	{
		right = left+1;
		if (right > hn || comp(heap[left], heap[right]) < 0)
		{
			if (comp(heap[left], heap[t]) < 0)
			{
				temp = heap[left];
				heap[left] = heap[t];
				heap[t] = temp;
				t = left;
			}
			else
			{
				return;
			}
		}
		else
		{
			if (comp(heap[right], heap[t]) < 0)
			{
				temp = heap[right];
				heap[right] = heap[t];
				heap[t] = temp;
				t = right;
			}
			else
			{
				return;
			}
		}
	}
}

int main()
{
	int i, n;
	hn = 0;
	while (gets(s))
	{
		if (*s == '#')
		{
			break;
		}
		++hn;
		sscanf(s+9, "%d%d", &id[hn], &tt[hn]);
		now[hn] = tt[hn];
		heap[hn] = hn;
	}
	for (i=hn; i>=1; i--)
	{
		heapdown(i);
	}
	scanf("%d", &n);
	while (n--)
	{
		printf("%d\n", id[heap[1]]);
		now[heap[1]] += tt[heap[1]];
		heapdown(1);
	}
	return 0;
}
