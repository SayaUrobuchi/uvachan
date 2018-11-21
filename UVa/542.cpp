#include <stdio.h>

int map[16][16];
char name[16][16];
double dp[5][16];

int main()
{
	int i, j, k, l, p, q;
	double r;
	while(gets(name[0]))
	{
		for(i=1; i<16; i++)
		{
			gets(name[i]);
		}
		for(i=0; i<16; i++)
		{
			for(j=0; j<16; j++)
			{
				scanf("%d", &map[i][j]);
			}
			dp[0][i] = 1.0;
		}
		for(i=1, k=2, l=1; i<5; i++, k+=k, l+=l)
		{
			for(j=0; j<16; j+=k)
			{
				for(p=j; p<j+l; p++)
				{
					for(q=j+l, r=0; q<j+k; q++)
					{
						r += map[p][q] * dp[i-1][q] / 100.0;
					}
					dp[i][p] = dp[i-1][p] * r;
				}
				for(; p<j+k; p++)
				{
					for(q=j, r=0; q<j+l; q++)
					{
						r += map[p][q] * dp[i-1][q] / 100.0;
					}
					dp[i][p] = dp[i-1][p] * r;
				}
			}
		}
		for(i=0; i<16; i++)
		{
			printf("%-11sp=%.2lf%%\n", name[i], dp[4][i]*100.0);
		}
		gets(name[0]);
	}
	return 0;
}
