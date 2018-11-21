/*
ID: sa072682
LANG: C
TASK: clocks
*/
#include <stdio.h>
#include <string.h>

int pre[262144], dp[9];
char max[262144], time[262144], str[9][6] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
char state[262144][10], chk;

void recursion(int now)
{
	int i;
	if(pre[now] != -1)
	{
		recursion(pre[now]);
		if(chk)
		{
			printf(" %d", max[now]+1);
		}
		else
		{
			printf("%d", max[now]+1);
			chk = 1;
		}
		return;
	}
	else
	{
		chk = 0;
		return;
	}
}

int main()
{
	int n, i, j, k, l, p, q, temp, now, sum;
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	dp[0] = 1;
	for(i=1; i<9; i++)
	{
		dp[i] = dp[i-1] * 3;
	}
	for(i=0; i<9; i++)
	{
		for(j=0; str[i][j]; j++)
		{
			str[i][j] -= 64;
		}
	}
	for(i=0, sum=0; i<9; i++)
	{
		scanf("%d", &n);
		state[0][i] = n / 3 + 47;
	}
	if(!strcmp(state[0], "333333333"))
	{
		printf("\n");
	}
	else
	{
		max[0] = 0;
		pre[0] = -1;
		time[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			//for(k=0; k<100; k++) printf("%d %s %d %d\n", i, state[i], max[i], time[i]);
			//printf("%d %d\n", i, j);
			p = max[i];
			if(time[i] != 3)
			{
				strcpy(state[j], state[i]);
				max[j] = p;
				pre[j] = i;
				time[j] = time[i] + 1;
				for(l=0; str[p][l]; l++)
				{
					state[j][str[p][l]-1] = ((state[j][str[p][l]-1] == 51) ? 48 : state[j][str[p][l]-1]+1);
				}
				if(!strcmp(state[j++], "333333333"))
				{
					break;
				}
			}
			for(p++; p<9; p++)
			{
				strcpy(state[j], state[i]);
				max[j] = p;
				pre[j] = i;
				time[j] = 1;
				for(l=0; str[p][l]; l++)
				{
					state[j][str[p][l]-1] = ((state[j][str[p][l]-1] == 51) ? 48 : state[j][str[p][l]-1]+1);
				}
				if(!strcmp(state[j++], "333333333"))
				{
					break;
				}
			}
			if(p < 9)
			{
				break;
			}
		}
		//while(1);
		recursion(j-1);
		printf("\n");
	}
	scanf(" ");
	return 0;
}
