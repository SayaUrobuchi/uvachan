#include <stdio.h>

int next[2000001], list[2000001], tbl[2000001];

int main()
{
	int n, i, j, k, c;
	next[0] = 1;
	for(i=1; i<2000000; i++)
	{
		next[i] = i + 2;
	}
	next[1999999] = 0;
	for(i=3, n=1000000; i<=n; i=next[i])
	{
		/*printf("%d %d\n", i, n);*/
		for(j=0, k=0, c=n/i, n-=c; c; j++, k=next[k])
		{
			if(j == i)
			{
				next[k] = next[next[k]];
				c--;
				j = 0;
			}
		}
	}
	for(i=0, k=0; j=next[i]; i=j, k++)
	{
		list[k] = j;
		printf("%d\n", j);
		tbl[j] = 1;
	}
	while(scanf("%d", &n) == 1)
	{
	}
	return 0;
}
