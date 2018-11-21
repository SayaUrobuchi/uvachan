#include <stdio.h>

int tbl[1000005];

int main()
{
	int n, i;
	tbl[1] = 2;
	i = 2;
	while(scanf("%d", &n) == 1)
	{
		for(; i<=n; i++)
		{
			tbl[i] = tbl[i-1] + (i-1)*i/2 + 1;
		}
		printf("%d\n", tbl[n]);
	}
	return 0;
}
