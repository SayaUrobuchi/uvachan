#include <stdio.h>
#include <string.h>

int ans, n, mask;
int board[16];
char map[16];

void dfs(int depth, int p, int q, int r)
{
	if (depth == n)
	{
		++ans;
		return;
	}
	int avail = ~(p | q | r | board[depth]) & mask;
	while (avail)
	{
		int last = (avail & -avail);
		dfs(depth+1, (p|last)<<1, (q|last)>>1, r|last);
		avail &= ~last;
	}
}

int main()
{
	int cas, i, j;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		mask = (1<<n)-1;
		for(i=0; i<n; i++)
		{
			scanf("%s", map);
			for (j=0, board[i]=0; j<n; j++)
			{
				if (map[j] == '*')
				{
					board[i] |= (1 << j);
				}
			}
		}
		ans = 0;
		dfs(0, 0, 0, 0);
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
