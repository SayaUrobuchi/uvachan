#include <iostream>
using namespace std;

const int N = 10;
const int DX[] = {-1, -1, -1, 0};
const int DY[] = {-1, 0, 1, -1};

int row[N], col[N], cnt[N];
char grp[N][N+5], board[N][N+5];

int main()
{
	int i, j, k;
	for (i=0; i<N; i++)
	{
		scanf("%s", grp[i]);
	}
	bool gg = false;
	for (i=0; i<N; i++)
	{
		scanf("%s", board[i]);
		for (j=0; j<N; j++)
		{
			if (board[i][j] == '*')
			{
				++row[i];
				++col[j];
				++cnt[grp[i][j]-'0'];
				for (k=0; k<4&&!gg; k++)
				{
					int tx = i + DX[k];
					int ty = j + DY[k];
					if (tx >= 0 && tx < N && ty >= 0 && ty < N
					 && board[tx][ty] == '*')
					{
						gg = true;
					}
				}
			}
		}
	}
	for (i=0; i<N&&!gg; i++)
	{
		gg |= (row[i] != 2 || col[i] != 2 || cnt[i] != 2);
	}
	puts(gg?"invalid":"valid");
	return 0;
}