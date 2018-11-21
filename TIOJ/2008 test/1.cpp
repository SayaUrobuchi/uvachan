#include <stdio.h>

#define BASE 1000000000

int f[1001][1001], l[1001];

int main()
{
	int n, i, j;
	f[0][0] = 0;
	f[1][0] = 1;
	l[0] = l[1] = 1;
	for(i=2; i<=1000; i++)
	{
		for(j=0; j<l[i-1]; j++)
		{
			f[i][j] += f[i-1][j] + f[i-2][j];
			if(f[i][j] >= BASE)
			{
				f[i][j] -= BASE;
				f[i][j+1]++;
			}
		}
		l[i] = l[i-1];
		if(f[i][j])
		{
			l[i]++;
		}
	}
	while(scanf("%d", &n) == 1)
	{
		printf("%d", f[n][l[n]-1]);
		for(i=l[n]-2; i>=0; i--)
		{
			printf("%09d", f[n][i]);
		}
		printf("\n");
	}
	return 0;
}
