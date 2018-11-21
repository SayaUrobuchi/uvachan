#include <stdio.h>

char chain[100][100], ans[3];
int n, total;

void dfs(int now, int depth, int direct)
{
	int i;
	if(depth == 3)
	{
		if(chain[ans[2] - 1][ans[0] - 1])
		{
			printf("%d %d %d\n", ans[0], ans[1], ans[2]);
			total++;
		}
		return;
	}
	if(direct)
	{
		for(i=now+1; i<n; i++)
		{
			if(chain[now][i])
			{
				ans[depth] = i + 1;
				dfs(i, depth + 1, 1);
			}
		}
	}
	else
	{
		for(i=0; i<now; i++)
		{
			if(chain[now][i])
			{
				ans[depth] = i + 1;
				dfs(i, depth + 1, 0);
			}
		}
	}
}

int main()
{
	int i, j;
	char bline;
	bline = 0;
	while(scanf("%d", &n)==1)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++) scanf("%d", &chain[i][j]);
		}
		total = 0;
		for(i=0; i<n; i++)
		{
			ans[0] = i + 1;
			dfs(i, 1, 0);
			dfs(i, 1, 1);
		}
		printf("total:%d\n\n", total);
	}
	return 0;
}
