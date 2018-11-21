#include <stdio.h>

int p, q, n, m, c;

void dfs(int son, int mon, int num, int last)
{
	if(num > m || p*mon < q*son)
	{
		return;
	}
	/*printf("%d/%d\n", son, mon);*/
	if(p*mon == q*son)
	{
		c++;
		return;
	}
	for(; mon*last<=n; last++)
	{
		dfs(son*last+mon, mon*last, num+1, last);
	}
}

int main()
{
	while(scanf("%d%d%d%d", &p, &q, &n, &m) == 4)
	{
		if(p == 0 && q == 0 && n == 0 && m == 0)
		{
			break;
		}
		dfs(c=0, 1, 0, 1);
		printf("%d\n", c);
	}
	return 0;
}
