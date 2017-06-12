#include <stdio.h>
#include <math.h>

int main()
{
	int ans, sq;
	long long n, i, j, p, q, lb;
	long long ii, jj, temp;
	while(scanf("%lld", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=1, lb=2, j=1LL<<20; ; )
		{
			if(i > j)
			{
				break;
			}
			ii = ((i+j) >> 1);
			if((ii+1)*(ii+1)*(ii+1) - ii*ii*ii > n)
			{
				j = ii - 1;
			}
			else
			{
				i = ii + 1;
				lb = ii;
			}
		}
		sq = sqrt(n)+1;
		for(i=1, ans=0; i<sq; i++)
		{
			if(n % i == 0)
			{
				j = n / i;
				for(p=1, q=lb; ; )
				{
					if(p > q)
					{
						break;
					}
					ii = ((p+q)>>1);
					temp = ii*ii + ii*(ii+i) + (ii+i)*(ii+i);
					if(temp == j)
					{
						ans = 1;
						j = ii + i;
						i = ii;
						break;
					}
					else if(temp > j)
					{
						q = ii - 1;
					}
					else
					{
						p = ii + 1;
					}
				}
				if(ans)
				{
					break;
				}
			}
		}
		if(ans)
		{
			printf("%lld %lld\n", j, i);
		}
		else
		{
			printf("No solution\n");
		}
	}
	return 0;
}
