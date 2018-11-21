#include <stdio.h>
#include <string.h>

int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int divisor[101][25];
int tbl[25];

int main()
{
	int n, m, i, j, k, temp, result;
	for(i=2, j=0; i<101; i++)
	{
		memcpy(divisor[i], divisor[i-1], sizeof(divisor[i]));
		if(i == prime[j])
		{
			divisor[i][j++] = 1;
		}
		else
		{
			for(k=0, temp=i; k<j&&temp>1; k++)
			{
				if(!(temp % prime[k]))
				{
					for(; !(temp%prime[k]); temp/=prime[k], divisor[i][k]++);
				}
			}
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		memcpy(tbl, divisor[n], sizeof(tbl));
		while(m--)
		{
			scanf("%d", &j);
			for(i=0; i<25; i++)
			{
				tbl[i] -= divisor[j][i];
			}
		}
		for(i=0, result=1; i<25; i++)
		{
			for(j=0; j<tbl[i]; j++)
			{
				result *= prime[i];
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
