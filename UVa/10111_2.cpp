#include <stdio.h>

int x, y;
char board[4][5];
char str[100];

int putx();

int chk()
{
	int i, j;
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(board[i][j] == '.')
			{
				break;
			}
		}
		if(j < 4)
		{
			break;
		}
	}
	if(i == 4)
	{
		return 0;
	}
	for(i=0; i<4; i++)
	{
		if(board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3])
		{
			return board[i][0];
		}
		if(board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i])
		{
			return board[0][i];
		}
	}
	if(board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3])
	{
		return board[0][0];
	}
	if(board[3][0] != '.' && board[3][0] == board[2][1] && board[2][1] == board[1][2] && board[1][2] == board[0][3])
	{
		return board[3][0];
	}
	return -1;
}

int puto()
{
	int i, j, temp;
	temp = chk();
	if(temp == 'x')
	{
		return 1;
	}
	else if(temp != -1)
	{
		return 0;
	}
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(board[i][j] == '.')
			{
				board[i][j] = 'o';
				if(!putx())
				{
					board[i][j] = '.';
					return 0;
				}
				board[i][j] = '.';
			}
		}
	}
	return 1;
}

int putx()
{
	int i, j;
	if(chk() != -1)
	{
		return 0;
	}
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(board[i][j] == '.')
			{
				board[i][j] = 'x';
				if(puto())
				{
					x = i;
					y = j;
					board[i][j] = '.';
					return 1;
				}
				board[i][j] = '.';
			}
		}
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%s", str) == 1)
	{
		if(str[0] == '$')
		{
			break;
		}
		for(i=0; i<4; i++)
		{
			scanf("%s", board[i]);
		}
		if(putx())
		{
			printf("(%d,%d)\n", x, y);
		}
		else
		{
			puts("#####");
		}
	}
	return 0;
}
