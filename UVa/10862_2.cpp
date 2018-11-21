#include <stdio.h>
#include <string.h>

int ary[2001][100], sum[100], num[2001];

int main()
{
	int n, i, j, k, len;
	ary[1][0] = 1;
	num[1] = 1;
	sum[0] = 2;
	len = 1;
	for(i=2; i<2001; i++)
	{
		memcpy(ary[i], ary[i-1], num[i-1] * 4);
		for(j=0; j<len; j++)
		{
			ary[i][j] += sum[j];
			if(ary[i][j] > 999999999)
			{
				ary[i][j+1]++;
				ary[i][j] -= 1000000000;
			}
		}
		if(ary[i][j])
		{
			j++;
		}
		num[i] = j;
		for(k=j, j=0; j<k; j++)
		{
			sum[j] += ary[i][j];
			if(sum[j] > 999999999)
			{
				sum[j+1]++;
				sum[j] -= 1000000000;
			}
		}
		if(sum[j])
		{
			k++;
		}
		len = k;
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		printf("%d", ary[n][(i=num[n]-1)]);
		for(i--; i>-1; i--)
		{
			printf("%09d", ary[n][i]);
		}
		printf("\n");
	}
	return 0;
}
