#include <stdio.h>

int list[25], n, t;
int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 49, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int gcd(int p, int q)
{
	if(p % q)
	{
		return gcd(q, p%q);
	}
	return q;
}

void dfs(int value, int depth, int last)
{
	int i, j, temp;
	if(depth == t)
	{
		if(value == n)
		{
			printf("%d", list[0]);
			for(i=1; i<t; i++)
			{
				printf(" %d", list[i]);
			}
			printf("\n");
		}
		return;
	}
	for(i=last, temp=(n-value)/(t-depth)+1; i<=temp; i++)
	{
		for(j=0; j<depth; j++)
		{
			if(gcd(i, list[j]) != 1)
			{
				break;
			}
		}
		if(j == depth)
		{
			list[depth] = i;
			dfs(value+i, depth+1, i);
		}
	}
}

int main()
{
	int cas, count, i, l;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &t);
		printf("Case %d:\n", ++cas);
		for(i=1, l=n/t+1; i<l; i++)
		{
			list[0] = i;
			dfs(i, 1, i);
		}
	}
	return 0;
}
