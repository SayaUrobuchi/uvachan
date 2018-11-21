#include <stdio.h>

int next[32], tbl[35], n, c, l;

int comp()
{
	int i, j;
	for(i=1, j=0; next[j]; i++, j=next[j])
	{
		if(next[j] > tbl[i])
		{
			return 1;
		}
		else if(next[j] < tbl[i])
		{
			return 0;
		}
	}
	return 0;
}

void dfs(int now)
{
	int i, j;
	if(now > n)
	{
		c++;
		if(c == 1 || comp())
		{
			for(l=1, j=0; next[j]; l++, j=next[j])
			{
				tbl[l] = next[j];
			}
		}
		return;
	}
	for(i=0; next[i]; i=next[i])
	{
		if(!(now % (i + (j = next[i]))))
		{
			next[i] = now;
			next[now] = j;
			dfs(now+1);
			next[i] = j;
		}
	}
}

int main()
{
	int i;
	scanf("%d", &n);
	next[0] = 1;
	next[1] = 0;
	c = 0;
	dfs(2);
	printf("%d\n", c);
	if(c)
	{
		printf("0");
		for(i=1; i<l; i++)
		{
			printf(" %d", tbl[i]);
		}
		printf("\n");
	}
	scanf(" ");
	return 0;
}
