#include <iostream>
using namespace std;

const int N = 128;
const int R = 128;
const int C = 128;
const int XLEN = 128;
const int YLEN = 128;

int row[N], col[N];
string str[R];
char board[N][XLEN][YLEN];

int main()
{
	int n, m, o, t, i, j, k, x, y, z;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		str[i].resize(m, '.');
	}
	scanf("%d", &o);
	for (i=0; i<o; i++)
	{
		scanf("%d%d", &row[i], &col[i]);
		for (j=0; j<row[i]; j++)
		{
			scanf("%s", board[i][j]);
		}
	}
	scanf("%d", &t);
	for (i=0; i<t; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		--z;
		for (j=0; j<row[z]; j++)
		{
			if (x+j < n)
			{
				for (k=0; k<col[z]&&y+k<m; k++)
				{
					str[x+j][y+k] = board[z][j][k];
				}
			}
		}
	}
	for (i=0; i<n; i++)
	{
		puts(str[i].c_str());
	}
	return 0;
}
