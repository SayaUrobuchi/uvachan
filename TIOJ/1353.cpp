#include <stdio.h>

int tbl[1000001];

int main()
{
	int n, m, i, j, k;
	for(i=2; i<=1000000; i+=2)
	{
		tbl[i]++;
	}
	for(i=3; i<=1000000; i+=2)
	{
		if(tbl[i] == 0)
		{
			for(j=i; j<=1000000; j+=i)
			{
				tbl[j]++;
			}
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=n, j=0; i<=m; i++)
		{
			if(tbl[i] > j)
			{
				j = tbl[i];
				k = i;
			}
		}
		printf("%d %d\n", k, j);
	}
	return 0;
}
