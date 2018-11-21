#include <stdio.h>

int tbl[1000005];

int main()
{
	int n, i, j, k;
	tbl[1] = 1;
	for(i=4; i<=1000000; i+=2)
	{
		tbl[i] = 1;
	}
	for(i=3; i<=1000; i+=2)
	{
		if(tbl[i] == 0)
		{
			for(j=i*i, k=i+i; j<=1000000; j+=k)
			{
				tbl[j] = 1;
			}
		}
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		printf("%d\n", tbl[n]);
	}
	return 0;
}
