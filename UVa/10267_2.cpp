#include <stdio.h>

char command[10], buf[100], board[250][251], newcolor, oldcolor;
int n, m, queue[62600][2];

int main()
{
	int i, j, in, in2, in3, x, y, xtmp, ytmp;
	n = 0;
	m = 0;
	while(scanf("%s", command) == 1)
	{
		if(command[0] && !command[1])
		{
			if(command[0] == 'X')
			{
				break;
			}
			else if(command[0] == 'I')
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
			else if(command[0] == 'C')
			{
				for(i=0; i<n; i++)
				{
					for(j=0; j<m; j++)
					{
						board[i][j] = 'O';
					}
				}
			}
			else if(command[0] == 'L')
			{
				scanf("%d%d%c", &in, &in2, &buf[0]);
				gets(buf);
				board[in2-1][in-1] = buf[0];
			}
			else if(command[0] == 'V')
			{
				scanf("%d%d%d%c", &j, &i, &in, &buf[0]);
				gets(buf);
				if(i > in)
				{
					in ^= i ^= in ^= i;
				}
				for(i--, j--, in; i<in; i++)
				{
					board[i][j] = buf[0];
				}
			}
			else if(command[0] == 'H')
			{
				scanf("%d%d%d%c", &j, &in, &i, &buf[0]);
				gets(buf);
				if(j > in)
				{
					in ^= j ^= in ^= j;
				}
				for(i--, j--, in; j<in; j++)
				{
					board[i][j] = buf[0];
				}
			}
			else if(command[0] == 'K')
			{
				scanf("%d%d%d%d%c", &in, &i, &in3, &in2, &buf[0]);
				gets(buf);
				if(i > in2)
				{
					in2 ^= i ^= in2 ^= i;
				}
				if(in > in3)
				{
					in ^= in3 ^= in ^= in3;
				}
				for(i--, in--, in2, in3; i<in2; i++)
				{
					for(j=in; j<in3; j++)
					{
						board[i][j] = buf[0];
					}
				}
			}
			else if(command[0] == 'F')
			{
				scanf("%d%d%c", &in, &in2, &buf[0]);
				gets(buf);
				oldcolor = board[--in2][--in];
				newcolor = buf[0];
				if(oldcolor == newcolor)
				{
					continue;
				}
				board[in2][in] = newcolor;
				queue[0][0] = in2;
				queue[0][1] = in;
				for(i=0, j=1; i<j; i++)
				{
					x = queue[i][0];
					y = queue[i][1];
					xtmp = x - 1;
					ytmp = y;
					if(xtmp > -1 && board[xtmp][ytmp] == oldcolor)
					{
						board[xtmp][ytmp] = newcolor;
						queue[j][0] = xtmp;
						queue[j++][1] = ytmp;
					}
					xtmp = x + 1;
					ytmp = y;
					if(xtmp < n && board[xtmp][ytmp] == oldcolor)
					{
						board[xtmp][ytmp] = newcolor;
						queue[j][0] = xtmp;
						queue[j++][1] = ytmp;
					}
					xtmp = x;
					ytmp = y - 1;
					if(ytmp > -1 && board[xtmp][ytmp] == oldcolor)
					{
						board[xtmp][ytmp] = newcolor;
						queue[j][0] = xtmp;
						queue[j++][1] = ytmp;
					}
					xtmp = x;
					ytmp = y + 1;
					if(ytmp < m && board[xtmp][ytmp] == oldcolor)
					{
						board[xtmp][ytmp] = newcolor;
						queue[j][0] = xtmp;
						queue[j++][1] = ytmp;
					}
				}
			}
			else if(command[0] == 'S')
			{
				scanf("%c", &buf[0]);
				gets(buf);
				printf("%s\n", buf);
				for(i=0; i<n; i++)
				{
					printf("%s\n", board[i]);
				}
			}
			else
			{
				gets(buf);
			}
		}
		else if(command[0])
		{
			gets(buf);
		}
	}
	return 0;
}
