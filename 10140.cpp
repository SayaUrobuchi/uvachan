#include <stdio.h>
#include <string.h>
#include <math.h>

char tbl[1000001];

int main()
{
	unsigned int n, m, i, j, k, c1, c2, d1, d2, temp, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(tbl, 1, sizeof(tbl));
		temp = sqrt(m) + 1;
		for(i=3; i<temp; i+=2)
		{
			j = n + i - n % i;
			j += (j==i) * i;
			for(; j<=m; j+=i)
			{
				tbl[j-n] = 0;
			}
		}
		if(n < 3)
		{
			j = 2;
		}
		else
		{
			j = 0;
		}
		for(i=n+1-n%2+(n==1)*2, c1=0, c2=2147483647, d1=d2=0, ans=0; i<=m; i+=2)
		{
			if(tbl[i-n])
			{
				if(j)
				{
					ans = 1;
					if(i - j < c2 - c1)
					{
						c1 = j;
						c2 = i;
					}
					if(i - j > d2 - d1)
					{
						d1 = j;
						d2 = i;
					}
				}
				j = i;
			}
		}
		if(ans)
		{
			printf("%d,%d are closest, %d,%d are most distant.\n", c1, c2, d1, d2);
		}
		else
		{
			printf("There are no adjacent primes.\n");
		}
	}
	return 0;
}
