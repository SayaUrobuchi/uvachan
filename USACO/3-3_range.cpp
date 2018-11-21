/*
	ID: sa072682
	LANG: C
	TASK: range
*/
#include <stdio.h>

int tbl[250], dp[250][251];
char map[250][251];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, i, j, k;
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%s", &map[i]);
		for(j=0; j<n; j++)
		{
			if(map[i][j] == '1')
			{
				if(i && j)
				{
					dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
				}
				else
				{
					dp[i][j] = 1;
				}
				for(k=2; k<=dp[i][j]; k++)
				{
					tbl[k]++;
				}
			}
		}
	}
	for(i=2; tbl[i]; i++)
	{
		printf("%d %d\n", i, tbl[i]);
	}
	scanf(" ");
	return 0;
}
