#include <stdio.h>
#include <string.h>

int n, m, id, ans;
int list[15];
int tbl[301];
int prime[100];
char buf[1000];
char final[1000];
char product[1000];

void dfs(int depth, int value, int last)
{
	int i, temp;
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
			if(!ans || strcmp(product, final) < 0)
			{
				strcpy(final, product);
			}
			ans = 1;
		}
		return;
	}
	if((!last && depth) || (depth > 1 && last == list[depth-2]))
	{
		last++;
	}
	temp = id - depth;
	for(i=last; i<m; i++)
	{
		if(temp * prime[i] > n)
		{
			return;
		}
		list[depth] = i;
		dfs(depth+1, value+prime[i], i);
	}
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
	while(scanf("%d%d", &n, &id) == 2)
	{
		if(!n && !id)
		{
			break;
		}
		printf("CASE %d:\n", ++cas);
		ans = 0;
		dfs(0, 0, 0);
		if(ans)
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
