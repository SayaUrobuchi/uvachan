#include <stdio.h>
#include <string.h>

#define BASE 10000000
#define BASELEN 7

int len[16][151];
int dp[16][151][500];
int temp[500];

int main()
{
	int n, m, i, j, k, l, tlen;
	int *p, *q;
	for(i=1; i<=150; i++)
	{
		len[0][i] = 1;
	}
	for(i=1; i<=15; i++)
	{
		dp[i][1][0] = i;
		len[i][1] = 1;
		memset(temp, 0, sizeof(temp));
		temp[0] = i;
		tlen = 1;
		for(j=2; j<=150; j++)
		{
			for(k=tlen-1; k>=0; k--)
			{
				temp[k] *= i;
				if(temp[k] >= BASE)
				{
					temp[k+1] += temp[k] / BASE;
					temp[k] %= BASE;
				}
			}
			/*for(; temp[k]; k++)
			{
				if(temp[k] >= BASE)
				{
					temp[k+1] += temp[k] / BASE;
					temp[k] %= BASE;
				}
			}
			tlen = k;*/
			if(temp[tlen])
			{
				tlen++;
			}
			/*if(i==5&&j<20)
			{
				printf("L: %d\n", j);
				for(k=tlen-1; k>=0; k--)
				{
					printf("%07d", temp[k]);
				}
				printf("\n");
			}*/
			for(k=0, l=len[i][j-1], p=dp[i][j], q=dp[i][j-1]; k<l||k<tlen; k++)
			{
				p[k] += q[k] + temp[k] * j;
				if(p[k] >= BASE)
				{
					p[k+1] += p[k] / BASE;
					p[k] %= BASE;
				}
			}
			/*for(; p[k]; k++)
			{
				if(p[k] >= BASE)
				{
					p[k+1] += p[k] / BASE;
					p[k] %= BASE;
				}
			}*/
			if(p[k])
			{
				k++;
			}
			len[i][j] = k;
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		p = dp[m][n];
		l = len[m][n];
		/*printf("%d\n", l);*/
		printf("%d", p[l-1]);
		for(i=l-2; i>=0; i--)
		{
			printf("%0*d", BASELEN, p[i]);
		}
		printf("\n");
	}
	return 0;
}
