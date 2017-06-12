#include <stdio.h>
#include <string.h>

int dp[11];
int queue[22000];
int loc[22000];
int last[22000];
int map[11][11], num[11];
int light[11][11], lnum[11];
int chk[11][2048];
int hash[1025];

void backtracing(int depth, int now)
{
	int temp, state;
	if((temp=last[now]) == -1)
	{
		printf("The problem can be solved in %d steps:\n", depth);
		return;
	}
	backtracing(depth+1, temp);
	if(loc[now] == loc[temp])
	{
		state = queue[now] - queue[temp];
		if(state > 0)
		{
			printf("- Switch on light in room %d.\n", hash[state]);
		}
		else
		{
			printf("- Switch off light in room %d.\n", hash[-state]);
		}
	}
	else
	{
		printf("- Move to room %d.\n", loc[now]);
	}
}

int main()
{
	int cas, n, m, o, i, j, k, state, now, temp;
	cas = 0;
	dp[1] = 1;
	hash[1] = 1;
	for(i=2; i<11; i++)
	{
		dp[i] = dp[i-1] + dp[i-1];
		hash[dp[i]] = i;
	}
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(!n && !m && !o)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		while(m--)
		{
			scanf("%d%d", &i, &j);
			map[i][num[i]++] = j;
			map[j][num[j]++] = i;
		}
		memset(lnum, 0, sizeof(lnum));
		while(o--)
		{
			scanf("%d%d", &i, &j);
			light[i][lnum[i]++] = j;
		}
		printf("Villa #%d\n", ++cas);
		if(n == 1)
		{
			printf("The problem can be solved in 0 steps:\n\n");
			continue;
		}
		queue[0] = 1;
		loc[0] = 1;
		last[0] = -1;
		memset(chk, 0, sizeof(chk));
		chk[1][1] = 1;
		for(i=0, j=1; i<j; i++)
		{
			state = queue[i];
			now = loc[i];
			for(k=0; k<num[now]; k++)
			{
				temp = map[now][k];
				if(!chk[temp][state] && (state & dp[temp]))
				{
					chk[temp][state] = 1;
					queue[j] = state;
					loc[j] = temp;
					last[j++] = i;
				}
			}
			for(k=0; k<lnum[now]; k++)
			{
				temp = light[now][k];
				if(state & dp[temp])
				{
					if(temp != now && !chk[now][state-dp[temp]])
					{
						chk[now][state-dp[temp]] = 1;
						queue[j] = state - dp[temp];
						loc[j] = now;
						last[j++] = i;
						if(now == n && state-dp[temp] == dp[n])
						{
							j--;
							break;
						}
					}
				}
				else
				{
					if(!chk[now][state+dp[temp]])
					{
						chk[now][state+dp[temp]] = 1;
						queue[j] = state + dp[temp];
						loc[j] = now;
						last[j++] = i;
					}
				}
			}
			if(k < lnum[now])
			{
				break;
			}
		}
		if(i == j)
		{
			printf("The problem cannot be solved.\n");
		}
		else
		{
			backtracing(0, j);
		}
		printf("\n");
	}
	return 0;
}
