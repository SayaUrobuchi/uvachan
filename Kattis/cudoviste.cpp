#include <stdio.h>
#include <string.h>

int dx[] = {0, 0, -1, -1};
int dy[] = {0, -1, 0, -1};
int cnt[8], tbl[128];
char board[128][128];

int main()
{
	int n, m, i, j, k, sum;
	tbl['.'] = 0;
	tbl['#'] = -1000;
	tbl['X'] = 1;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(cnt, 0, sizeof(cnt));
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			if (i)
			{
				for (j=1; j<m; j++)
				{
					for (k=0, sum=0; k<4; k++)
					{
						sum += tbl[board[i+dx[k]][j+dy[k]]];
					}
					if (sum >= 0)
					{
						cnt[sum]++;
					}
				}
			}
		}
		for (i=0; i<=4; i++)
		{
			printf("%d\n", cnt[i]);
		}
	}
	return 0;
}
