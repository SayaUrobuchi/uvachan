#include <stdio.h>
#include <string.h>

#define N 1000

int tbl[N+1];

int main()
{
	int cas, i, j, k, cc;
	memset(tbl, -1, sizeof(tbl));
	tbl[1] = 1;
	for (i=2; i<N; i++)
	{
		cc = i+1;
		for (j=2+(i&1), k=1+(i&1); j*j<=i&&cc<=N; j+=k)
		{
			if (i % j == 0)
			{
				cc += j;
				if (j*j != i)
				{
					cc += i/j;
				}
			}
		}
		if (cc <= N)
		{
			tbl[cc] = i;
		}
	}
	cas = 0;
	while (scanf("%d", &i) == 1)
	{
		if (!i)
		{
			break;
		}
		printf("Case %d: %d\n", ++cas, tbl[i]);
	}
	return 0;
}
