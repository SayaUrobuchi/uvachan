#include <iostream>
using namespace std;

int h[] = {4, 1, 2, 2, 3};
int num[][5] = {
	{1, 1, 1, 1},
	{3},
	{2, 2},
	{1, 3},
	{1, 2, 2}
};
int siz[] = {4, 3, 4, 4, 5};
int board[32];

int main()
{
	int r, c, y, n, i, j, mx, del, block;
	char t;
	cin >> r >> c >> n;
	for (i=0, block=r*c, del=0; i<n; i++)
	{
		cin >> t >> y;
		t -= 'A';
		for (j=0, mx=0; j<h[t]; j++)
		{
			mx = max(mx, board[y+j]+num[t][j]);
		}
		if (mx > c)
		{
			++del;
		}
		else
		{
			for (j=0; j<h[t]; j++)
			{
				board[y+j] = mx;
			}
			block -= siz[t];
		}
	}
	cout << block << " " << del << "\n";
	return 0;
}
