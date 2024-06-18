#include <iostream>
using namespace std;

const int N = 505;
const char LAND = '.';
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const char *key = "RDLU";

int tbl[128];
char path[N], board[N][N];

int main()
{
	int n, m, o, i, j, k;
	for (i=0; i<4; i++)
	{
		tbl[key[i]] = i;
	}
	scanf("%d%d%d", &n, &m, &o);
	scanf("%s", path);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	int ans = 0;
	for (i=1; i+1<n; i++)
	{
		for (j=1; j+1<m; j++)
		{
			if (board[i][j] == LAND)
			{
				int x = i;
				int y = j;
				bool ok = true;
				for (k=0; k<o; k++)
				{
					x += DX[tbl[path[k]]];
					y += DY[tbl[path[k]]];
					if (board[x][y] != LAND)
					{
						ok = false;
						break;
					}
				}
				ans += ok;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
