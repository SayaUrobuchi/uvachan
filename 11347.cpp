#include <stdio.h>
#include <string.h>

int prime[1000];
int tbl[1000];
int ary[1001][1000];
char str[100];

int main()
{
	int cas, count, n, i, j, k, temp, len;
	long long limit, result;
	limit = 1000000000;
	limit *= 1000000000;
	prime[0] = 2;
	ary[2][0] = 1;
	for(i=3, k=1; i<1001; i++)
	{
		for(j=0, temp=i; j<k; j++)
		{
			if(prime[j] * prime[j] > i)
			{
				break;
			}
			for(; !(temp%prime[j]); temp/=prime[j], ary[i][j]++);
		}
		if(temp == i)
		{
			prime[k] = i;
			ary[i][k++] = 1;
		}
		else if(temp > 1)
		{
			for(; j<k; j++)
			{
				if(prime[j] == temp)
				{
					ary[i][j]++;
					break;
				}
			}
		}
	}
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		gets(str);
		len = strlen(str);
		memset(tbl, 0, sizeof(tbl));
		for(i=n; i>1; i-=len)
		{
			for(j=0; j<k; j++)
			{
				tbl[j] += ary[i][j];
			}
		}
		for(j=0, result=1; j<k; j++)
		{
			if(limit / result >= tbl[j] + 1)
			{
				result *= tbl[j] + 1;
			}
			else
			{
				result = 0;
				break;
			}
		}
		if(result)
		{
			printf("Case %d: %lld\n", ++cas, result);
		}
		else
		{
			printf("Case %d: Infinity\n", ++cas);
		}
	}
	return 0;
}
