#include <iostream>
using namespace std;

const int WAY[][3][2] = 
{
	{{0, 0}, {0, 1}, {0, 2}},
	{{1, 0}, {1, 1}, {1, 2}},
	{{2, 0}, {2, 1}, {2, 2}},
	{{0, 0}, {1, 0}, {2, 0}},
	{{0, 1}, {1, 1}, {2, 1}},
	{{0, 2}, {1, 2}, {2, 2}},
	{{0, 0}, {1, 1}, {2, 2}},
	{{2, 0}, {1, 1}, {0, 2}},
};
const int QN = sizeof(WAY) / sizeof(WAY[0]);
const int X = 0;
const int Y = 1;
const char PLAYER = 'O';

char board[8][8];

int main()
{
	int i;
	for (i=0; i<3; i++)
	{
		scanf("%s", board[i]);
	}
	bool win = false;
	for (i=0; !win&&i<QN; i++)
	{
		if (board[WAY[i][0][X]][WAY[i][0][Y]] == PLAYER)
		{
			win = (board[WAY[i][0][X]][WAY[i][0][Y]] == board[WAY[i][1][X]][WAY[i][1][Y]]
				&& board[WAY[i][0][X]][WAY[i][0][Y]] == board[WAY[i][2][X]][WAY[i][2][Y]]);
		}
	}
	puts(win?"Jebb":"Neibb");
	return 0;
}
