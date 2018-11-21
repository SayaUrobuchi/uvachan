#include <stdio.h>
#include <string.h>

char map[8][8], stat[8][3], ary[8], dp[40][8];

int main()
{
	int n, state, i, j, k;
	char buf[100];
	for(i=0; i<8; i++)
	{
		n = i;
		k = 0;
		while(n)
		{
			stat[i][k++] = n % 2;
			n /= 2;
		}
		for(j=0; j<=i; j++)
		{
			map[i][j] = (stat[i][1] == stat[j][2] && stat[i][0] == stat[j][1]);
			map[j][i] = (stat[j][1] == stat[i][2] && stat[j][0] == stat[i][1]);
		}
	}
	while(scanf("%d%d%s", &state, &n, buf) == 3)
	{
		k = 0;
		memset(ary, 0, sizeof(ary));
		while(state)
		{
			ary[k++] = state % 2;
			printf("%d %d\n", k-1, ary[k-1]);
			state /= 2;
		}
		memset(dp, 0, sizeof(dp));
		for(i=0; i<8; i++)
		{
			dp[0][i] = (ary[i] == buf[0] - 48);
			printf("%d %d %d\n", 0, i, dp[0][i]);
		}
		for(i=1; buf[i]; i++)
		{
			for(j=0; j<8; j++)
			{
				if(ary[j] == buf[i] - 48)
				{
					for(k=0; k<8; k++)
					{
						if(dp[i-1][k] && map[k][j])
						{
							break;
						}
					}
					if(k < 8)
					{
						dp[i][j] = 1;
						printf("%d %d\n", i, j);
					}
				}
			}
		}
		for(i--, j=0; j<8; j++)
		{
			if(dp[i][j])
			{
				for(k=0; k<8; k++)
				{
					printf("XDD %d %d %d %d\n", j, k, map[j][k], dp[0][k]);
					if(map[j][k] && dp[0][k])
					{
						break;
					}
				}
				if(k < 8)
				{
					break;
				}
			}
		}
		if(j < 8)
		{
			printf("REACHABLE\n");
		}
		else
		{
			printf("GARDEN OF EDEN\n");
		}
	}
	return 0;
}
