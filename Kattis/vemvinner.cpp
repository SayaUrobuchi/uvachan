#include <iostream>
using namespace std;

const int TIE = 0;
const int JOHAN = 1;
const int ABDULLAH = 2;
const char *nam[] = {"ingen", "Johan", "Abdullah"};
const int EMPTY = '_';
const int J = 'X';
const int A = 'O';

char board[3][3], s[8];

int main()
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			scanf("%s", s);
			board[i][j] = *s;
		}
	}
	int winner = TIE;
	for (i=0; i<3; i++)
	{
		if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{
			if (board[i][0] == J)
			{
				winner = JOHAN;
			}
			else
			{
				winner = ABDULLAH;
			}
		}
		if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			if (board[0][i] == J)
			{
				winner = JOHAN;
			}
			else
			{
				winner = ABDULLAH;
			}
		}
	}
	if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		if (board[0][0] == J)
		{
			winner = JOHAN;
		}
		else
		{
			winner = ABDULLAH;
		}
	}
	if (board[2][0] != EMPTY && board[2][0] == board[1][1] && board[2][0] == board[0][2])
	{
		if (board[2][0] == J)
		{
			winner = JOHAN;
		}
		else
		{
			winner = ABDULLAH;
		}
	}
	printf("%s har vunnit\n", nam[winner]);
	return 0;
}
