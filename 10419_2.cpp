#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, id, ans;
int list[15];
int tbl[301];
int prime[100];
char buf[1000];
char final[1000];
char product[1000];
char s1[100], s2[100];

int comp(const void *p, const void *q)
{
	sprintf(s1, "%d", *(int*)p);
	sprintf(s2, "%d", *(int*)q);
	return strcmp(s1, s2);
}

int dfs(int depth, int value, int last)
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
			sprintf(product, "%d", prime[list[0]]);
			for(i=1; i<depth; i++)
			{
				sprintf(buf, "+%d", prime[list[i]]);
				strcat(product, buf);
			}
			strcpy(final, product);
			return 1;
		}
		return 0;
	}
	if((prime[last] == 2 && depth && list[depth-1] == last) || (depth > 1 && last == list[depth-2]))
	{
		last++;
	}
	temp = id - depth;
	for(i=last; i<m; i++)
	{
		list[depth] = i;
		if(dfs(depth+1, value+prime[i], i))
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int cas, i, j, p, q;
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
	m = j;
	qsort(prime, m, sizeof(int), comp);
	while(scanf("%d%d", &n, &id) == 2)
	{
		if(!n && !id)
		{
			break;
		}
		printf("CASE %d:\n", ++cas);
		ans = 0;
		if(dfs(0, 0, 0))
		{
			printf("%s\n", final);
		}
		else
		{
			printf("No Solution.\n");
		}
	}
	return 0;
}
