#include <stdio.h>
#include <stdlib.h>

int head[20001];
int knight[20001];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, m, i, j, cost;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &head[i]);
		}
		for(i=0; i<m; i++)
		{
			scanf("%d", &knight[i]);
		}
		qsort(head, n, sizeof(int), comp);
		qsort(knight, m, sizeof(int), comp);
		for(i=0, j=0, cost=0; i<n; i++)
		{
			for(; j<m; j++)
			{
				if(knight[j] >= head[i])
				{
					break;
				}
			}
			if(j == m)
			{
				break;
			}
			cost += knight[j++];
		}
		if(i == n)
		{
			printf("%d\n", cost);
		}
		else
		{
			printf("Loowater is doomed!\n");
		}
	}
	return 0;
}
