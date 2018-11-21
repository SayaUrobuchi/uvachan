#include <stdio.h>

#define BASE 1000000

int f[1001][5001], l[1001];

int main()
{
	int n, i, j;
	f[0][0] = 1;
	l[0] = 1;
	for(i=1; i<=1000; i++)
	{
		for(j=0; j<l[i-1]; j++)
		{
			f[i][j] = f[i-1][j] * i;
		}
		for(j=0; j<l[i-1]; j++)
		{
			if(f[i][j] >= BASE)
			{
				f[i][j+1] += f[i][j] / BASE;
				f[i][j] %= BASE;
			}
		}
		for(; f[i][j]; j++)
		{
			f[i][j+1] += f[i][j] / BASE;
			f[i][j] %= BASE;
		}
		l[i] = j;
	}
	while(scanf("%d", &n) == 1)
	{
		printf("%d", f[n][l[n]-1]);
		for(i=l[n]-2; i>=0; i--)
		{
			printf("%06d", f[n][i]);
		}
		printf("\n");
	}
	return 0;
}
