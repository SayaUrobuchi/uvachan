#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int final;
int ans[13];
int next[14];
int turn[13][5];
int list[13];
int ftemp[13];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

void check()
{
	int i, j, sum;
	int *ptr;
	sum = 0;
	memset(ans, 0, sizeof(ans));
	for(j=0; j<6; j++)
	{
		ptr = turn[list[j]];
		for(i=0; i<5; i++)
		{
			if(ptr[i] == j+1)
			{
				ans[j] += j+1;
			}
		}
		sum += ans[j];
	}
	if(sum >= 63)
	{
		sum += 35;
	}
	ptr = turn[list[j]];
	for(i=0; i<5; i++)
	{
		ans[j] += ptr[i];
	}
	sum += ans[j];
	j++;
	ptr = turn[list[j]];
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
			ans[j] += ptr[i];
		}
	}
	sum += ans[j];
	j++;
	ptr = turn[list[j]];
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
			ans[j] += ptr[i];
		}
	}
	sum += ans[j];
	j++;
	ptr = turn[list[j]];
	i = 0;
	if(ptr[i] == ptr[i+1] && ptr[i] == ptr[i+2] && ptr[i] == ptr[i+3] && ptr[i] == ptr[i+4])
	{
		ans[j] = 50;
	}
	sum += ans[j];
	j++;
	ptr = turn[list[j]];
	i = 0;
	if(ptr[i]+1 == ptr[i+1] && ptr[i+1]+1 == ptr[i+2] && ptr[i+2]+1 == ptr[i+3])
	{
		ans[j] = 25;
	}
	else
	{
		i++;
		if(ptr[i]+1 == ptr[i+1] && ptr[i+1]+1 == ptr[i+2] && ptr[i+2]+1 == ptr[i+3])
		{
			ans[j] = 25;
		}
	}
	sum += ans[j];
	j++;
	ptr = turn[list[j]];
	for(i=1; i<5; i++)
	{
		if(ptr[i] != ptr[i-1] + 1)
		{
			break;
		}
	}
	if(i == 5)
	{
		ans[j] = 35;
	}
	sum += ans[j];
	j++;
	ptr = turn[list[j]];
	if(ptr[0] == ptr[1] && ptr[2] == ptr[3] && ptr[2] == ptr[4])
	{
		ans[j] = 40;
	}
	else if(ptr[0] == ptr[1] && ptr[0] == ptr[2] && ptr[3] == ptr[4])
	{
		ans[j] = 40;
	}
	sum += ans[j];
	if(sum > final)
	{
		final = sum;
		memcpy(ftemp, ans, sizeof(ftemp));
	}
}

void dfs(int depth)
{
	int i, j;
	if(depth == 13)
	{
		check();
		return;
	}
	for(i=0; j=next[i]; i=next[i])
	{
		list[depth] = i;
		next[i] = next[j];
		dfs(depth+1);
		next[i] = j;
	}
}

int main()
{
	int i, j;
	while(scanf("%d", &turn[0][0]) == 1)
	{
		next[0] = 1;
		for(i=1; i<5; i++)
		{
			scanf("%d", &turn[0][i]);
		}
		qsort(turn[0], 5, sizeof(int), comp);
		for(i=1; i<13; i++)
		{
			next[i] = i+1;
			for(j=0; j<5; j++)
			{
				scanf("%d", &turn[i][j]);
			}
			qsort(turn[i], 5, sizeof(int), comp);
		}
		next[i] = 0;
		final = 0;
		dfs(0);
		for(i=0; i<13; i++)
		{
			printf("%d ", ftemp[i]);
		}
		for(i=0, j=0; i<6; i++)
		{
			j += ans[i];
		}
		if(j >= 63)
		{
			printf("35 ");
		}
		else
		{
			printf("0 ");
		}
		printf("%d\n", final);
	}
	return 0;
}
