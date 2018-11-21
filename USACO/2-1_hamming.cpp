/*
	ID: sa072682
	LANG: C
	TASK: hamming
*/
#include <stdio.h>
#include <string.h>

int dp[10], list[70], n, b, d;
char map[256][256], str[256][9], s[9];

void dfs(int value, int depth)
{
	int i, j, dis;
	if(depth == b)
	{
		s[depth] = 0;
		strcpy(str[value], s);
		for(i=0; i<value; i++)
		{
			for(j=0, dis=0; j<b; j++)
			{
				dis += (s[j] != str[i][j]);
			}
			if(dis >= d)
			{
				map[value][i] = map[i][value] = 1;
			}
		}
		return;
	}
	s[depth] = 1;
	dfs(value, depth+1);
	s[depth] = 2;
	dfs(value+dp[b-depth-1], depth+1);
}

char dfs2(int depth, int last)
{
	int i, j;
	if(depth == n)
	{
		printf("%d", list[0]);
		for(i=1; i<n; i++)
		{
			if(i % 10)
			{
				printf(" %d", list[i]);
			}
			else
			{
				printf("\n%d", list[i]);
			}
		}
		printf("\n");
		return 1;
	}
	for(i=last; i<dp[b]; i++)
	{
		for(j=0; j<depth; j++)
		{
			if(!map[list[j]][i])
			{
				break;
			}
		}
		if(j == depth)
		{
			list[depth] = i;
			if(dfs2(depth+1, i+1))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, k, l;
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	dp[0] = 1;
	for(i=1; i<10; i++)
	{
		dp[i] = dp[i-1] * 2;
	}
	scanf("%d%d%d", &n, &b, &d);
	dfs(0, 0);
	for(i=0; i<dp[b]; i++)
	{
		list[0] = i;
		if(dfs2(1, i+1))
		{
			break;
		}
	}
	scanf(" ");
	return 0;
}
