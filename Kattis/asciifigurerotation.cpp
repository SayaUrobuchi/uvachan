#include <iostream>
using namespace std;

const int N = 105;
const int M = 105;

int len[N], alen[M];
char board[N][M], ans[M][N], buf[M];
char tbl[128];

int main()
{
	int n, m, i, j;
	bool first = true;
	tbl[' '] = ' ';
	tbl['+'] = '+';
	tbl['-'] = '|';
	tbl['|'] = '-';
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		fgets(buf, M, stdin);
		for (i=0, m=0; i<n; i++)
		{
			fgets(board[i], M, stdin);
			for (j=0; board[i][j]>=' '; j++);
			len[i] = j;
			m = max(m, j);
		}
		for (i=0; i<m; i++)
		{
			for (j=0, alen[i]=0; j<n; j++)
			{
				if (len[n-j-1] <= i)
				{
					ans[i][j] = ' ';
				}
				else
				{
					ans[i][j] = tbl[board[n-j-1][i]];
				}
				if (ans[i][j] != ' ')
				{
					alen[i] = j + 1;
				}
			}
		}
		if (!first)
		{
			puts("");
		}
		first = false;
		for (i=0; i<m; i++)
		{
			printf("%.*s\n", alen[i], ans[i]);
		}
	}
	return 0;
}