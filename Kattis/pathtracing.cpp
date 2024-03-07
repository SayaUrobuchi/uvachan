#include <iostream>
#include <cstring>
using namespace std;

const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const int SX = 501;
const int SY = 501;
const int N = 503;
const int N2 = (N << 1);

int tbl[128];
char wall[N], board[N2][N2];
char buf[8];

int main()
{
	int i;
	int x = SX;
	int y = SY;
	int lx = x;
	int rx = x;
	int ly = y;
	int ry = y;
	tbl['r'] = 0;
	tbl['d'] = 1;
	tbl['l'] = 2;
	tbl['u'] = 3;
	memset(board, ' ', sizeof(board));
	memset(wall, '#', sizeof(wall));
	board[x][y] = 'S';
	while (scanf("%s", buf) == 1)
	{
		int d = tbl[*buf];
		x += DX[d];
		y += DY[d];
		lx = min(lx, x);
		rx = max(rx, x);
		ly = min(ly, y);
		ry = max(ry, y);
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
		}
	}
	board[x][y] = 'E';
	printf("%.*s\n", ry-ly+3, wall);
	for (i=lx; i<=rx; i++)
	{
		printf("#%.*s#\n", ry-ly+1, board[i]+ly);
	}
	printf("%.*s\n", ry-ly+3, wall);
	return 0;
}
