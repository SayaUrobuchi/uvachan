#include <stdio.h>
#include <string.h>

int n;
int used[1800000];
int dp[1800000];
int heat[7][7], res[7][7];
int times[7];

int recursion(int num, int state)
{
	int i, j, h, r, temp, stemp, next;
	if(used[state])
	{
		return dp[state];
	}
	used[state] = 1;
	if(num == 1)
	{
		return dp[state]=0;
	}
	dp[state] = 2147483647;
	for(i=0, temp=state; i<n; i++, temp/=11)
	{
		if(temp % 11)
		{
			stemp = state - times[i];
			for(j=0; j<n; j++, stemp/=11)
			{
				if(stemp % 11)
				{
					h = heat[i][j];
					/*printf("XDD %d %d %d\n", i, j, h);*/
					r = res[i][j];
					next = state - times[i] - times[j] + times[r];
					if(recursion(num-1, next) + h < dp[state])
					{
						dp[state] = dp[next] + h;
					}
				}
			}
		}
	}
	/*printf("%d: %d\n", state, dp[state]);*/
	return dp[state];
}

int main()
{
	int count, m, i, j, state, temp;
	times[0] = 1;
	for(i=1; i<7; i++)
	{
		times[i] = times[i-1] * 11;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d%d", &res[i][j], &heat[i][j]);
				res[i][j]--;
			}
		}
		state = 0;
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d", &temp);
			state += times[temp-1];
		}
		memset(used, 0, sizeof(used));
		printf("%d\n", recursion(m, state));
		scanf("%*s");
	}
	return 0;
}
