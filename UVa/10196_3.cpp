#include <iostream>
using namespace std;

const int SIZ = 8;
const char EMPTY = '.';
const char BLACK_KING = 'k';
const char WHITE_KING = 'K';
const string typ_str = ".pnbrqkPNBRQK";
const int WAY[] = {0, // empty
	2, 8, 4, 4, 8, 8, // pnbrqk
	2, 8, 4, 4, 8, 8  // PNBRQK
};
const int DIS[] = {0, // empty
	1, 1, 8, 8, 8, 1, // pnbrqk
	1, 1, 8, 8, 8, 1  // PNBRQK
};
const int DX[][8] = {
	{}, // empty
	{1, 1}, // p
	{-2, -2, -1, -1, 1, 1, 2, 2}, // n
	{-1, -1, 1, 1}, // b
	{0, 1, 0, -1}, // r
	{0, 1, 0, -1, 1, 1, -1, -1}, // q
	{0, 1, 0, -1, 1, 1, -1, -1}, // k
	{-1, -1}, // P
	{-2, -2, -1, -1, 1, 1, 2, 2}, // N
	{-1, -1, 1, 1}, // B
	{0, 1, 0, -1}, // R
	{0, 1, 0, -1, 1, 1, -1, -1}, // Q
	{0, 1, 0, -1, 1, 1, -1, -1}  // K
};
const int DY[][8] = {
	{}, // empty
	{-1, 1}, // p
	{1, -1, 2, -2, 2, -2, 1, -1}, // n
	{-1, 1, -1, 1}, // b
	{1, 0, -1, 0}, // r
	{1, 0, -1, 0, 1, -1, 1, -1}, // q
	{1, 0, -1, 0, 1, -1, 1, -1}, // k
	{-1, 1}, // P
	{1, -1, 2, -2, 2, -2, 1, -1}, // N
	{-1, 1, -1, 1}, // B
	{1, 0, -1, 0}, // R
	{1, 0, -1, 0, 1, -1, 1, -1}, // Q
	{1, 0, -1, 0, 1, -1, 1, -1}  // K
};

int typ_tbl[128];
string board[SIZ];

int main()
{
	int cas = 0;
	int i, j, w, d;
	for (i=0; i<typ_str.size(); i++)
	{
		typ_tbl[ typ_str[i] ] = i;
	}
	while (cin >> board[0])
	{
		for (i=1; i<SIZ; i++)
		{
			cin >> board[i];
		}
		bool black_checked = false;
		bool white_checked = false;
		bool is_end = true;
		for (i=0; i<SIZ; i++)
		{
			for (j=0; j<SIZ; j++)
			{
				bool is_white = true;
				int typ = typ_tbl[ board[i][j] ];
				if (board[i][j] != EMPTY)
				{
					is_end = false;
					if (board[i][j] >= 'a' && board[i][j] <= 'z')
					{
						is_white = false;
					}
				}
				for (w=0; w<WAY[typ]; w++)
				{
					bool is_blocked = false;
					for (d=1; d<=DIS[typ]&&!is_blocked; d++)
					{
						int tx = i + DX[typ][w] * d;
						int ty = j + DY[typ][w] * d;
						if (tx >= 0 && tx < SIZ && ty >= 0 && ty < SIZ)
						{
							if (board[tx][ty] != EMPTY)
							{
								is_blocked = true;
								if (is_white && board[tx][ty] == BLACK_KING)
								{
									black_checked = true;
								}
								if (!is_white && board[tx][ty] == WHITE_KING)
								{
									white_checked = true;
								}
							}
						}
					}
				}
			}
		}
		if (is_end)
		{
			break;
		}
		++cas;
		cout << "Game #" << cas << ": ";
		if (white_checked)
		{
			cout << "white king is in check.\n";
		}
		else if (black_checked)
		{
			cout << "black king is in check.\n";
		}
		else
		{
			cout << "no king is in check.\n";
		}
	}
	return 0;
}
