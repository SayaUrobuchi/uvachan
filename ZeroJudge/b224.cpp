#include <stdio.h>

int qx[10005], qy[10005], qs[10005];
int dx[]={0, 1, 0, -1}, dy[]={1, 0, -1, 0};
char board[105][105];

int main()
{
	int n, i, j, k, x, y, s, sx, sy, tx, ty;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		sx = -1;
		for(i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			if(sx == -1)
			{
				for(j=0; board[i][j]; j++)
				{
					if(board[i][j] == 'K')
					{
						sx = i;
						sy = j;
						break;
					}
				}
			}
		}
		qx[0] = sx;
		qy[0] = sy;
		qs[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			s = qs[i];
			if(board[x][y] == '@'+1)
			{
				break;
			}
			for(k=0; k<4; k++)
			{
				tx = x+dx[k];
				ty = y+dy[k];
				if(board[tx][ty] == '.' || board[tx][ty] == '@')
				{
					board[tx][ty]++;
					qx[j] = tx;
					qy[j] = ty;
					qs[j] = s+1;
					j++;
				}
			}
		}
		if(i < j)
		{
			printf("%d\n", s);
		}
		else
		{
			printf("= =\"\n");
		}
	}
	return 0;
}
