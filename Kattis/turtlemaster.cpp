#include <iostream>
using namespace std;

const int R = 0;
const char CASTLE = 'C';
const char ICE = 'I';
const char DIAMOND = 'D';
const char EMPTY = '.';

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

char board[16][16], cmd[1024];

int main()
{
	int i, x, y, d, tx, ty;
	bool bug;
	while (scanf("%s", board[0]) == 1)
	{
		for (i=1; i<8; i++)
		{
			scanf("%s", board[i]);
		}
		scanf("%s", cmd);
		x = 7;
		y = 0;
		d = R;
		bug = false;
		for (i=0; cmd[i]; i++)
		{
			if (cmd[i] == 'F')
			{
				x += dx[d];
				y += dy[d];
				if (x < 0 || x >= 8 || y < 0 || y >= 8)
				{
					bug = true;
					break;
				}
				if (board[x][y] == CASTLE || board[x][y] == ICE)
				{
					bug = true;
					break;
				}
			}
			else if (cmd[i] == 'L')
			{
				d = ((d+3) & 3);
			}
			else if (cmd[i] == 'R')
			{
				d = ((d+1) & 3);
			}
			else
			{
				tx = x + dx[d];
				ty = y + dy[d];
				if (tx < 0 || tx >= 8 || ty < 0 || ty >= 8)
				{
					bug = true;
					break;
				}
				if (board[tx][ty] != ICE)
				{
					bug = true;
					break;
				}
				board[tx][ty] = EMPTY;
			}
		}
		if (bug || board[x][y] != DIAMOND)
		{
			puts("Bug!");
		}
		else
		{
			puts("Diamond!");
		}
	}
	return 0;
}
