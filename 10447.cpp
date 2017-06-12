#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, id, o;
int list[13];
int tbl[301];
int prime[65];
int times[65];
int index[65];
char s1[100], s2[100];

int comp(const void *p, const void *q)
{
	sprintf(s1, "%d", prime[*(int*)p]);
	sprintf(s2, "%d", prime[*(int*)q]);
	return strcmp(s1, s2);
}

int dfs(int last, int depth, int value)
{
	int i, temp;
	if(value > n)
	{
		return 0;
	}
	if(depth == id)
	{
		if(value == n)
		{
			return 1;
		}
		return 0;
	}
	for(i=last; i<o; i++)
	{
		if(times[temp=index[i]])
		{
			list[depth] = i;
			times[temp]--;
			if(dfs(i, depth+1, value+prime[temp]))
			{
				times[temp]++;
				return 1;
			}
			times[temp]++;
		}
	}
	return 0;
}

int main()
{
	int cas, count, i, j, m, p, q;
	cas = 0;
	prime[0] = 2;
	for(i=3, j=1; i<20; i+=2)
	{
		if(!tbl[i])
		{
			prime[j++] = i;
			for(p=i*i, q=i+i; p<300; p+=q)
			{
				tbl[p] = 1;
			}
		}
	}
	for(; i<300; i+=2)
	{
		if(!tbl[i])
		{
			prime[j++] = i;
		}
	}
	o = j;
	for(i=0; i<=61; i++)
	{
		index[i] = i;
	}
	qsort(index, o, sizeof(int), comp);
	scanf("%d", &count);
	while(count--)
	{
		printf("Block %d:\n", ++cas);
		for(i=1; i<=61; i++)
		{
			scanf("%d", &times[i]);
		}
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &n, &id, &times[0]);
			printf("Query %d:\n", i+1);
			if(!times[0] && n%2 != id%2)
			{
				printf("No Solution.\n");
			}
			else
			{
				if(dfs(0, 0, 0))
				{
					printf("%d", prime[index[list[0]]]);
					for(j=1; j<id; j++)
					{
						printf("+%d", prime[index[list[j]]]);
					}
					printf("\n");
				}
				else
				{
					printf("No Solution.\n");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
