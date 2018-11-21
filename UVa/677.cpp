#include <stdio.h>
#include <string.h>

int n, m, c;
int map[11][11];
int chk[11];
int list[11];

void dfs(int now, int depth)
{
	int i;
	if(depth == m)
	{
		printf("(1");
		for(i=0; i<depth; i++)
		{
			printf(",%d", list[i]);
		}
		printf(")\n");
		c++;
		return;
	}
	for(i=2; i<=n; i++)
	{
		if(map[now][i] && !chk[i])
		{
			chk[i] = 1;
			list[depth] = i;
			dfs(i, depth+1);
			chk[i] = 0;
		}
	}
}

int main()
{
	int flag, i, j;
	flag = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		if(flag)
		{
			printf("\n");
		}
		flag = 1;
		memset(chk, 0, sizeof(chk));
		chk[1] = 1;
		c = 0;
		dfs(1, 0);
		if(!c)
		{
			printf("no walk of length %d\n", m);
		}
		scanf("%d", &n);
	}
	return 0;
}
