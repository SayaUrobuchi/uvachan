#include <stdio.h>

int len[1005], ary[1005][1005];

int main()
{
	int n, i, j;
	ary[0][0] = 0;
	len[0] = 1;
	ary[1][0] = 1;
	len[1] = 1;
	ary[2][0] = 1;
	len[2] = 1;
	for(i=3; i<=1000; i++)
	{
		for(j=0; j<len[i-1]; j++)
		{
			ary[i][j] += ary[i-2][j]+ary[i-3][j];
			if(ary[i][j] > 999999999)
			{
				ary[i][j] -= 1000000000;
				ary[i][j+1]++;
			}
		}
		len[i] = len[i-1];
		if(ary[i][j])
		{
			len[i]++;
		}
	}
	while(scanf("%d", &n) == 1)
	{
		printf("%d", ary[n][len[n]-1]);
		for(i=len[n]-2; i>=0; i--)
		{
			printf("%09d", ary[n][i]);
		}
		printf("\n");
	}
	return 0;
}
