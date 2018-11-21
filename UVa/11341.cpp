#include <stdio.h>
#include <string.h>

int n, m, ans;
int ary[10][100];
int tbl[10][11];

void dfs(int depth, int hour, int value)
{
	int i;
	if(hour > m)
	{
		return;
	}
	if(depth == n)
	{
		if(value > ans)
		{
			ans = value;
		}
		return;
	}
	for(i=10; i>4; i--)
	{
		if(tbl[depth][i] <= m)
		{
			dfs(depth+1, hour+tbl[depth][i], value+i);
		}
	}
}

int main()
{
	int count, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			for(j=0; j<11; j++)
			{
				tbl[i][j] = 200;
			}
			for(j=0; j<m; j++)
			{
				scanf("%d", &ary[i][j]);
				if(tbl[i][ary[i][j]] > j + 1)
				{
					tbl[i][ary[i][j]] = j + 1;
				}
			}
		}
		ans = 0;
		dfs(0, 0, 0);
		if(ans)
		{
			printf("Maximal possible average mark - %.2lf.\n", (double)ans/n + 0.000001);
		}
		else
		{
			printf("Peter, you shouldn't have played billiard that much.\n");
		}
	}
	return 0;
}
