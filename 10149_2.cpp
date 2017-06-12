#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int turn[13][5];
int used[13][8192];
int dp[13][8192];
int mark[13][8192];
int from[13][8192];
int hash[8193];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int check(int j, int tar)
{
	int i, sum;
	int *ptr;
	sum = 0;
	if(j < 6)
	{
		ptr = turn[tar];
		for(i=0; i<5; i++)
		{
			if(ptr[i] == j+1)
			{
				sum += j+1;
			}
		}
	}
	else if(j == 6)
	{
		ptr = turn[tar];
		for(i=0; i<5; i++)
		{
			sum += ptr[i];
		}
	}
	else if(j == 7)
	{
		ptr = turn[tar];
		for(i=0; i<3; i++)
		{
			if(ptr[i] == ptr[i+1] && ptr[i] == ptr[i+2])
			{
				break;
			}
		}
		if(i < 3)
		{
			for(i=0; i<5; i++)
			{
				sum += ptr[i];
			}
		}
	}
	else if(j == 8)
	{
		ptr = turn[tar];
		for(i=0; i<2; i++)
		{
			if(ptr[i] == ptr[i+1] && ptr[i] == ptr[i+2] && ptr[i] == ptr[i+3])
			{
				break;
			}
		}
		if(i < 2)
		{
			for(i=0; i<5; i++)
			{
				sum += ptr[i];
			}
		}
	}
	else if(j == 9)
	{
		ptr = turn[tar];
		i = 0;
		if(ptr[i] == ptr[i+1] && ptr[i] == ptr[i+2] && ptr[i] == ptr[i+3] && ptr[i] == ptr[i+4])
		{
			sum = 50;
		}
	}
	else if(j == 10)
	{
		ptr = turn[tar];
		i = 0;
		if(ptr[i]+1 == ptr[i+1] && ptr[i+1]+1 == ptr[i+2] && ptr[i+2]+1 == ptr[i+3])
		{
			sum = 25;
		}
		else
		{
			i++;
			if(ptr[i]+1 == ptr[i+1] && ptr[i+1]+1 == ptr[i+2] && ptr[i+2]+1 == ptr[i+3])
			{
				sum = 25;
			}
		}
	}
	else if(j == 11)
	{
		ptr = turn[tar];
		for(i=1; i<5; i++)
		{
			if(ptr[i] != ptr[i-1] + 1)
			{
				break;
			}
		}
		if(i == 5)
		{
			sum = 35;
		}
	}
	else
	{
		ptr = turn[tar];
		if(ptr[0] == ptr[1] && ptr[2] == ptr[3] && ptr[2] == ptr[4])
		{
			sum = 40;
		}
		else if(ptr[0] == ptr[1] && ptr[0] == ptr[2] && ptr[3] == ptr[4])
		{
			sum = 40;
		}
	}
	return sum;
}

int recursion(int state, int num)
{
	int i, tar, temp;
	if(used[num][state])
	{
		return dp[num][state];
	}
	used[num][state] = 1;
	if(!num)
	{
		return dp[num][state]=check(0, hash[state]);
	}
	dp[num][state] = -1;
	for(i=0; i<13; i++)
	{
		if(state & (1<<i))
		{
			tar = state - (1<<i);
			if((temp=(recursion(tar, num-1)+check(num, i))) > dp[num][state])
			{
				dp[num][state] = temp;
				mark[num][state] = mark[num-1][tar];
				from[num][state] = tar;
			}
		}
	}
	if(num == 5 && dp[num][state] >= 63)
	{
		mark[num][state] = 1;
		dp[num][state] += 35;
	}
	return dp[num][state];
}

void backtracking(int state, int num)
{
	if(!num)
	{
		printf("%d ", dp[num][state]);
	}
	else
	{
		backtracking(from[num][state], num-1);
		if(num == 5 && mark[12][(1<<13)-1])
		{
			printf("%d ", dp[num][state]-dp[num-1][from[num][state]]-35);
		}
		else
		{
			printf("%d ", dp[num][state]-dp[num-1][from[num][state]]);
		}
	}
}

int main()
{
	int i, j, ans;
	for(i=0; i<13; i++)
	{
		hash[1<<i] = i;
	}
	while(scanf("%d", &turn[0][0]) == 1)
	{
		for(i=1; i<5; i++)
		{
			scanf("%d", &turn[0][i]);
		}
		qsort(turn[0], 5, sizeof(int), comp);
		for(i=1; i<13; i++)
		{
			for(j=0; j<5; j++)
			{
				scanf("%d", &turn[i][j]);
			}
			qsort(turn[i], 5, sizeof(int), comp);
		}
		memset(used, 0, sizeof(used));
		memset(mark, 0, sizeof(mark));
		ans = recursion((1<<13)-1, 12);
		backtracking((1<<13)-1, 12);
		if(mark[12][(1<<13)-1])
		{
			printf("35 ");
		}
		else
		{
			printf("0 ");
		}
		printf("%d\n", ans);
	}
	return 0;
}
