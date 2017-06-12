#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[1000][51], heap[10000], dis[1000], dp[1000], n;

void swap(int *p, int *q)
{
	*p ^= *q ^= *p ^= *q;
}

void heapup(int now)
{
	int tmp;
	if(now == 1) return;
	tmp = now / 2;
	if(dis[heap[now]] < dis[heap[tmp]])
	{
		swap(&heap[now], &heap[tmp]);
		heapup(tmp);
	}
}

void heapdown(int now)
{
	int tmp;
	tmp = now * 2;
	if(tmp > n) return;
	if(tmp < n && dis[heap[tmp]] > dis[heap[tmp + 1]])
	{
		tmp++;
	}
	if(dis[heap[now]] > dis[heap[tmp]])
	{
		swap(&heap[now], &heap[tmp]);
		heapdown(tmp);
	}
}

int main()
{
	int p, d, now, count, i, j, tmp, ctmp, ptmp, *ptr, min;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &p, &d);
		for(i=0; i<p; i++)
		{
			map[i][0] = 1;
		}
		while(d--)
		{
			scanf("%d%d", &i, &j);
			map[i][map[i][0]++] = j;
			map[j][map[j][0]++] = i;
		}
		memset(dis, 0, p * 4);
		dis[0] = -1;
		n = 0;
		for(i=1, ctmp=map[0][0]; i<ctmp; i++)
		{
			dis[map[0][i]] = 1;
			heap[++n] = map[0][i];
		}
		ptmp = p - 1;
		min = 0;
		while(ptmp)
		{
			now = heap[1];
			heap[1] = heap[n--];
			heapdown(1);
			if(dis[now] != -1)
			{
				ptmp--;
				ctmp = dis[now];
				dp[now] = ctmp;
				dis[now] = -1;
				ctmp++;
				for(i=1, tmp=map[now][0], ptr=map[now] + 1; i<tmp; i++, ptr++)
				{
					if(!dis[*ptr] || dis[*ptr] > ctmp)
					{
						dis[*ptr] = ctmp;
						heap[++n] = *ptr;
						heapup(n);
					}
				}
			}
		}
		for(i=1; i<p; i++)
		{
			printf("%d\n", dp[i]);
		}
		if(count) printf("\n");
	}
	return 0;
}
