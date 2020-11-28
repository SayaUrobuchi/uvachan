#include <iostream>
#include <cstring>
#include <algorithm>

int board[4][4], temp[4][4];

void trans(int d, int t)
{
	int i, j;
	if (!(d&3))
	{
		return;
	}
	if (d == 2)
	{
		for (i=0; i<4; i++)
		{
			std::reverse(board[i], board[i]+4);
		}
	}
	else if (d == 1)
	{
		while (t--)
		{
			for (i=0; i<4; i++)
			{
				for (j=0; j<4; j++)
				{
					temp[i][j] = board[j][i];
				}
			}
			memcpy(board, temp, sizeof(board));
		}
	}
	else
	{
		while (t--)
		{
			for (i=0; i<4; i++)
			{
				for (j=0; j<4; j++)
				{
					temp[i][j] = board[3-j][i];
				}
			}
			memcpy(board, temp, sizeof(board));
		}
	}
}

int main()
{
	int i, j, d, last;
	bool mg;
	while (scanf("%d%d%d%d", &board[0][0], &board[0][1], &board[0][2], &board[0][3]) == 4)
	{
		for (i=1; i<4; i++)
		{
			for (j=0; j<4; j++)
			{
				scanf("%d", &board[i][j]);
			}
		}
		scanf("%d", &d);
		trans(d, 1);
		for (i=0; i<4; i++)
		{
			for (j=0, last=-1, mg=true; j<4; j++)
			{
				if (board[i][j])
				{
					if (!mg && board[i][j] == board[i][last])
					{
						mg = true;
						board[i][last] <<= 1;
					}
					else
					{
						++last;
						mg = false;
						board[i][last] = board[i][j];
					}
				}
			}
			for (++last; last<4; last++)
			{
				board[i][last] = 0;
			}
		}
		trans(d, 3);
		for (i=0; i<4; i++)
		{
			printf("%d", board[i][0]);
			for (j=1; j<4; j++)
			{
				printf(" %d", board[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
