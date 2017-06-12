#include <stdio.h>
#include <string.h>

#define N 3000

int n, ans;
int list[N], listx[N], listy[N];
int final[N], fx[N], fy[N];
char board[55][55];

void dfs(int x, int y, int depth)
{
	int i, j, l, lim;
	/*printf("%d %d\n", x, y);*/
	if(depth >= ans)
	{
		return;
	}
	if(y == n)
	{
		y = 0;
		x++;
		if(x == n)
		{
			ans = depth;
			memcpy(final, list, sizeof(final));
			memcpy(fx, listx, sizeof(fx));
			memcpy(fy, listy, sizeof(fy));
			return;
		}
	}
	if(board[x][y])
	{
		for(i=y+1; i<n&&board[x][i]; i++);
		dfs(x, i, depth);
	}
	else
	{
		for(i=y, l=1; l<n&&x+l<=n&&i<n&&!board[x][i]; i++, l++);
		/*printf("L %d\n", l);*/
		l--;
		lim = (l >> 1);
		for(i=x; i<x+l; i++)
		{
			memset(board[i]+y, 1, l);
		}
		listx[depth] = x;
		listy[depth] = y;
		for(i=l; i>=1; i--)
		{
			if(i >= 1)
			{
				list[depth] = i;
				if(depth+1 >= ans)
				{
					for(i=x; i<x+l; i++)
					{
						memset(board[i]+y, 0, l);
					}
					return;	
				}	
				dfs(x, y+i, depth+1);
			}
			for(j=x; j<x+i; j++)
			{
				board[j][y+i-1] = 0;
			}
			for(j=y; j<y+i; j++)
			{
				board[x+i-1][j] = 0;
			}
		}
	}
}

int main()
{
	int count, i;
	/*freopen("1.txt", "w", stdout);*/
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		if(n % 2)
		{
			ans = 10000;
			memset(board, 0, sizeof(board));
			dfs(0, 0, 0);
			/*if(ans == 10000) printf("XD\n");
			else
			{*/
			printf("%d\n", ans);
			for(i=0; i<ans; i++)
			{
				printf("%d %d %d\n", fx[i]+1, fy[i]+1, final[i]);
			}
			/*}*/
		}
		else
		{
			n >>= 1;
			printf("4\n");
			printf("%d %d %d\n", 1, 1, n);
			printf("%d %d %d\n", 1, n+1, n);
			printf("%d %d %d\n", n+1, 1, n);
			printf("%d %d %d\n", n+1, n+1, n);
		}
	}
	return 0;
}
