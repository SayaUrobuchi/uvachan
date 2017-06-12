#include <stdio.h>

char command[10], buf[1000], board[250][251], oldcolor, newcolor;
int n, m;

void floodfill(int x, int y)
{
    int xtmp, ytmp;
	xtmp = x - 1;
	ytmp = y;
	if(xtmp > -1 && board[xtmp][ytmp] == oldcolor)
	{
		board[xtmp][ytmp] = newcolor;
		floodfill(xtmp, ytmp);
	}
	xtmp = x + 1;
	ytmp = y;
	if(xtmp < n && board[xtmp][ytmp] == oldcolor)
	{
		board[xtmp][ytmp] = newcolor;
		floodfill(xtmp, ytmp);
	}
	xtmp = x;
	ytmp = y - 1;
	if(ytmp > -1 && board[xtmp][ytmp] == oldcolor)
	{
		board[xtmp][ytmp] = newcolor;
		floodfill(xtmp, ytmp);
	}
	xtmp = x;
	ytmp = y + 1;
	if(ytmp < m && board[xtmp][ytmp] == oldcolor)
	{
		board[xtmp][ytmp] = newcolor;
		floodfill(xtmp, ytmp);
	}
}

int main()
{
	int i, j, in, in2, in3;
	while(scanf("%s", command) == 1)
	{
		if(command[0] == 'X')
		{
			break;
		}
		if(command[0] == 'I')
		{
			scanf("%d%d", &m, &n);
			for(i=0; i<n; i++)
			{
				for(j=0; j<m; j++)
				{
					board[i][j] = 'O';
				}
				board[i][j] = 0;
			}
		}
		if(command[0] == 'C')
		{
			for(i=0; i<n; i++)
			{
				for(j=0; j<m; j++)
				{
					board[i][j] = 'O';
				}
			}
		}
		if(command[0] == 'L')
		{
			scanf("%d%d%s", &in, &in2, buf);
			board[in2-1][in-1] = buf[0];
		}
		if(command[0] == 'V')
		{
			scanf("%d%d%d%s", &j, &i, &in, buf);
			for(i--, j--, in; i<in; i++)
			{
				board[i][j] = buf[0];
			}
		}
		if(command[0] == 'H')
		{
			scanf("%d%d%d%s", &j, &in, &i, buf);
			for(i--, j--, in; j<in; j++)
			{
				board[i][j] = buf[0];
			}
		}
		if(command[0] == 'K')
		{
			scanf("%d%d%d%d%s", &i, &in, &in2, &in3, buf);
			for(i--, in--, in2, in3; i<in2; i++)
			{
				for(j=in; j<in3; j++)
				{
					board[i][j] = buf[0];
				}
			}
		}
		if(command[0] == 'F')
		{
			scanf("%d%d%s", &in, &in2, buf);
			oldcolor = board[--in2][--in];
			newcolor = buf[0];
			if(oldcolor != newcolor)
			{
				floodfill(in2, in);
			}
		}
		if(command[0] == 'S')
		{
			scanf("%s", buf);
			printf("%s\n", buf);
			for(i=0; i<n; i++)
			{
				printf("%s\n", board[i]);
			}
		}
	}
	return 0;
}
