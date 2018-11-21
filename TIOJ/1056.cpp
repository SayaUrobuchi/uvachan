#include <stdio.h>

int state[19683];
int board[9];
char map[3][4];

int decode(char ch)
{
	if(ch == '.')
	{
		return 0;
	}
	else if(ch == 'O')
	{
		return 1;
	}
	else if(ch == 'X')
	{
		return 2;
	}
	return 20000;
}

int maptrans()
{
	int i, j, k, res;
	for(i=0, k=1, res=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(decode(map[i][j]) == 20000)
			{
				return 2;
			}
			res += decode(map[i][j]) * k;
			k *= 3;
		}
	}
	return res;
}

int trans()
{
	int i, j, res;
	for(i=0, j=1, res=0; i<9; i++, j*=3)
	{
		res += board[i] * j;
	}
	return res;
}

int win()
{
	int i;
	for(i=0; i<3; i++)
	{
		if(board[0+i] == board[3+i] && board[3+i] == board[6+i] && board[0+i])
		{
			return 1;
		}
		if(board[i*3] == board[i*3+1] && board[i*3+1] == board[i*3+2] && board[i*3])
		{
			return 1;
		}
	}
	return (board[0] == board[4] && board[4] == board[8] && board[0]) || (board[2] == board[4] && board[4] == board[6] && board[2]);
}

void put(int type)
{
	int i, temp;
	if(state[temp=trans()])
	{
		return;
	}
	state[temp] = 1;
	if(win())
	{
		return;
	}
	for(i=0; i<9; i++)
	{
		if(!board[i])
		{
			board[i] = type;
			put(3-type);
			board[i] = 0;
		}
	}
}

int main()
{
	put(1);
	while(scanf("%s%s%s", map[0], map[1], map[2]) == 3)
	{
		if(state[maptrans()])
		{
			printf("POSSIBLE\n");
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
