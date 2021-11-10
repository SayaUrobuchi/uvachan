#include <iostream>
using namespace std;

const int NONE = 0;
const int BLACK = 1;
const int WHITE = 2;
const int KING = 5;
const string key = "pnbrqk";
const string king = "_kK";

const int dx[][8] = {
	{1, 1},
	{1, 1, -1, -1, 2, 2, -2, -2},
	{1, 1, -1, -1},
	{0, 1, 0, -1},
	{0, 1, 0, -1, 1, 1, -1, -1},
	{0, 1, 0, -1, 1, 1, -1, -1}
};

const int dy[][8] = {
	{1, -1},
	{2, -2, 2, -2, 1, -1, 1, -1},
	{1, -1, 1, -1},
	{1, 0, -1, 0},
	{1, 0, -1, 0, 1, -1, 1, -1},
	{1, 0, -1, 0, 1, -1, 1, -1}
};

const int dz[] = {1, 1, 8, 8, 8, 1};

const int dc[] = {2, 8, 4, 4, 8, 8};

const string typ[] = {"no", "black", "white"};

int ans, tbl[128], to_typ[128];
char board[16][16];

int get_chess(int t)
{
	return tbl[t|32];
}

bool diff(int a, int b)
{
	return (a & 32) ^ (b & 32);
}

bool check(int x, int y)
{
	int t = get_chess(board[x][y]);
	int d = 1;
	int i, k, nx, ny;
	if (board[x][y] == 'P')
	{
		d = -1;
	}
	for (k=0; k<dc[t]; k++)
	{
		for (i=1; i<=dz[t]; i++)
		{
			nx = x + dx[t][k] * i * d;
			ny = y + dy[t][k] * i;
			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
			{
				if (get_chess(board[nx][ny]) == KING && diff(board[nx][ny], board[x][y]))
				{
					ans = to_typ[board[nx][ny]];
					return true;
				}
				else if (board[nx][ny] != '.')
				{
					break;
				}
			}
		}
	}
	return false;
}

int main()
{
	int cas, i, j;
	bool appear;
	cas = 0;
	for (i=0; i<key.size(); i++)
	{
		tbl[key[i]] = i;
	}
	for (i=1; i<king.size(); i++)
	{
		to_typ[king[i]] = i;
	}
	while (cin >> board[0])
	{
		for (i=1; i<8; i++)
		{
			cin >> board[i];
		}
		for (i=0, appear=false, ans=NONE; i<8&&ans==NONE; i++)
		{
			for (j=0; j<8&&ans==NONE; j++)
			{
				if (board[i][j] != '.')
				{
					appear = true;
					if (check(i, j))
					{
						break;
					}
				}
			}
		}
		if (!appear)
		{
			break;
		}
		cout << "Game #" << ++cas << ": " << typ[ans] << " king is in check.\n";
	}
	return 0;
}
