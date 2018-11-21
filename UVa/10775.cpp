#include <stdio.h>

#define CLEN 3
#define RLEN 3

int r[RLEN][CLEN] = {	{-5, 1, 13}, 
						{4, 4, 1}, 
						{1, -5, -14}};
int rstart[RLEN] = {8, 1, 6};

int mod(int n, int m)
{
	if(n < 1)
	{
		return n + m;
	}
	if(n > m)
	{
		return n - m;
	}
	return n;
}

int main()
{
	int n, i, j, k, maxnum, now, times;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		if(n % 2)
		{
			for(i=0, k=0, times=n/6, maxnum=n*3; i<RLEN; i++, k+=9)
			{
				for(j=0, now=rstart[i]+k*times; j<n; now+=r[i][(j++)%3], now=mod(now, maxnum))
				{
					if(j)
					{
						printf(" %d", now);
					}
					else
					{
						printf("%d", now);
					}
				}
				printf("\n");
			}
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
