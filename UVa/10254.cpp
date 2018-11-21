#include <stdio.h>
#include <string.h>

#define BASE 1000000000

int tlen;
int len[10005];
int dp[10005][10];
int temp[10];

int main()
{
	int n, i, j, k, l, q;
	int *p, *p2;
	len[0] = 1;
	temp[0] = 1;
	tlen = 1;
	for(i=1, j=0, k=0; i<=10000; i++, k++)
	{
		if(k > j)
		{
			j++;
			k = 0;
			for(l=tlen-1; l>=0; l--)
			{
				temp[l] <<= 1;
				if(temp[l] >= BASE)
				{
					temp[l+1]++;
					temp[l] -= BASE;
				}
			}
			if(temp[tlen])
			{
				tlen++;
			}
			/*printf("%d", temp[tlen-1]);
			for(l=tlen-2; l>=0; l--)
			{
				printf("%09d", temp[l]);
			}
			printf("\n");*/
		}
		len[i] = len[i-1];
		for(l=0, p=dp[i], p2=dp[i-1], q=len[i-1]; l<q||l<tlen; l++)
		{
			p[l] += p2[l] + temp[l];
			if(p[l] >= BASE)
			{
				p[l+1]++;
				p[l] -= BASE;
			}
		}
		if(p[q])
		{
			len[i]++;
		}
		/*printf("%d\n", len[i]);*/
	}
	while(scanf("%d", &n) == 1)
	{
		p = dp[n];
		q = len[n];
		printf("%d", p[q-1]);
		for(i=q-2; i>=0; i--)
		{
			printf("%09d", p[i]);
		}
		printf("\n");
	}
	return 0;
}
