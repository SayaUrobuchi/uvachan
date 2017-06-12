#include <stdio.h>
#include <string.h>

int prime[670];
int fact[5001][670];
int son[670];
int num[110];

int main()
{
	int n, m, i, j, k, temp, total, len;
	prime[0] = 2;
	fact[2][0] = 1;
	for(i=3, j=1; i<5001; i++)
	{
		memcpy(fact[i], fact[i-1], sizeof(fact[i]));
		for(k=0, temp=i; prime[k]*prime[k]<=i; k++)
		{
			if(!(temp % prime[k]))
			{
				for(; !(temp%prime[k]); temp/=prime[k], fact[i][k]++);
			}
		}
		if(temp == i)
		{
			prime[j] = i;
			fact[i][j++] = 1;
		}
		else if(temp > 1)
		{
			for(; prime[k]!=temp; k++);
			fact[i][k]++;
		}
	}
	total = j;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(son, 0, sizeof(son));
		while(n--)
		{
			scanf("%d%d", &i, &j);
			for(k=0; k<total; k++)
			{
				son[k] += fact[i][k];
				son[k] -= fact[j][k] + fact[i-j][k];
			}
		}
		while(m--)
		{
			scanf("%d%d", &i, &j);
			for(k=0; k<total; k++)
			{
				son[k] += fact[j][k] + fact[i-j][k];
				son[k] -= fact[i][k];
			}
		}
		for(i=0; i<total; i++)
		{
			if(son[i] < 0)
			{
				break;
			}
		}
		if(i < total)
		{
			printf("0\n");
		}
		else
		{
			memset(num, 0, sizeof(num));
			num[0] = 1;
			for(i=0, len=1; i<total; i++)
			{
				for(j=0; j<son[i]; j++)
				{
					for(k=len-1; k>-1; k--)
					{
						num[k] *= prime[i];
						if(num[k] >= 100000)
						{
							num[k+1] += num[k] / 100000;
							num[k] %= 100000;
						}
					}
					for(k=0; k<len; k++)
					{
						if(num[k] >= 100000)
						{
							num[k+1] += num[k] / 100000;
							num[k] %= 100000;
						}
					}
					for(; num[k]; k++)
					{
						if(num[k] >= 100000)
						{
							num[k+1] += num[k] / 100000;
							num[k] %= 100000;
						}
					}
					len = k;
					if(len > 20)
					{
						break;
					}
				}
				if(len > 20)
				{
					break;
				}
			}
			if(i < total)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d", num[len-1]);
				for(i=len-2; i>-1; i--)
				{
					printf("%05d", num[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
