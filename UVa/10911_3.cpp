#include <stdio.h>
#include <string.h>
#include <math.h>

int m;
int used[65536];
int px[16], py[16];
double dp[65536];
double map[16][16];
char name[16][25];

double getdis(int x, int y)
{
	return sqrt((double)x*x+y*y);
}

double recursion(int num, int state)
{
	int i, j, s;
	if(used[state])
	{
		return dp[state];
	}
	used[state] = 1;
	if(!num)
	{
		return dp[state]=0;
	}
	dp[state] = 1e30;
	for(i=0; i<m; i++)
	{
		if(state & (1<<i))
		{
			s = state - (1<<i);
			for(j=i+1; j<m; j++)
			{
				if(state & (1<<j))
				{
					if(recursion(num-1, s-(1<<j)) + map[i][j] < dp[state])
					{
						dp[state] = recursion(num-1, s-(1<<j)) + map[i][j];
					}
				}
			}
			break;
		}
	}
	return dp[state];
}

int main()
{
	int cas, n, i, j;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0, m=(n<<1); i<m; i++)
		{
			scanf("%s%d%d", name[i], &px[i], &py[i]);
			for(j=0; j<i; j++)
			{
				map[j][i] = getdis(px[i]-px[j], py[i]-py[j]);
			}
		}
		memset(used, 0, sizeof(used));
		printf("Case %d: %.2lf\n", ++cas, recursion(n, (1<<m)-1));
	}
	return 0;
}
