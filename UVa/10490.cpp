#include <stdio.h>
#include <math.h>

char prime[32];
unsigned int two[32];
int now, son[1000], son2[1000];
long long ary[32], tmp, sum;

int main()
{
	int i, j, k, l, p, q, sq;
	two[0] = 1;
	for(i=1; i<32; i++)
	{
		two[i] = two[i-1] * 2;
	}
	prime[2] = 1;
	prime[3] = 1;
	prime[5] = 1;
    prime[7] = 1;
    prime[11] = 1;
    prime[13] = 1;
    prime[17] = 1;
    prime[19] = 1;
    prime[23] = 1;
    prime[29] = 1;
    prime[31] = 1;
	son[0] = 1;
	son2[0] = 1;
	for(i=2; i<32; i++)
	{
		now = two[i-1];
		sq = sqrt(now) + 1;
		for(j=2, k=1; j<sq; j++)
		{
			if(!(now % j))
			{
				if(j * j == now)
				{
					son[k++] = j;
				}
				else
				{
					son[k++] = j;
					son[k++] = now / j;
				}
			}
		}
		son[k++] = now;
		now = two[i] - 1;
		sq = sqrt(now) + 1;
		for(j=2, l=1; j<sq; j++)
		{
			if(!(now % j))
			{
				if(j * j == now)
				{
					son2[l++] = j;
				}
				else
				{
					son2[l++] = j;
					son2[l++] = now / j;
				}
			}
		}
		son2[l++] = now;
		tmp = (long long)two[i-1] * (two[i]-1);
		sum = -tmp;
		for(p=0; p<k; p++)
		{
			for(q=0; q<l; q++)
			{
				sum += (long long)son[p] * son2[q];
			}
		}
		if(sum == tmp)
		{
			ary[i] = tmp;
		}
	}
	while(scanf("%d", &i) == 1)
	{
		if(!i)
		{
			break;
		}
		if(ary[i])
		{
			printf("Perfect: %lld!\n", ary[i]);
		}
		else
		{
			if(prime[i])
			{
				printf("Given number is prime. But, NO perfect number is available.\n");
			}
			else
			{
				printf("Given number is NOT prime! NO perfect number is available.\n");
			}
		}
	}
	return 0;
}
