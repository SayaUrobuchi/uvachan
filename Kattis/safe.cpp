#include <iostream>

int ucnt;
int used[1048576], qq[1048576], qs[1048576];
int board[3][3];

int enc(int b[][3])
{
	int i, res;
	for (i=0, res=0; i<9; i++)
	{
		res |= (b[i/3][i%3] << (i<<1));
	}
	return res;
}

void dec(int b[][3], int t)
{
	int i;
	for (i=0; i<9; i++)
	{
		b[i/3][i%3] = ((t >> (i<<1)) & 3);
	}
}

int click(int b[][3], int x, int y)
{
	int i, res;
	for (i=0, res=0; i<9; i++)
	{
		res |= (((b[i/3][i%3]+(i/3==x||i%3==y?1:0))&3) << (i<<1));
	}
	return res;
}

int main()
{
	int i, j, k, cur, nxt, ans;
	while (scanf("%d%d%d", &board[0][0], &board[0][1], &board[0][2]) == 3)
	{
		for (i=1; i<3; i++)
		{
			scanf("%d%d%d", &board[i][0], &board[i][1], &board[i][2]);
		}
		qq[0] = enc(board);
		qs[0] = 0;
		++ucnt;
		used[qq[0]] = ucnt;
		ans = -1;
		for (i=0, j=1; i<j; i++)
		{
			cur = qq[i];
			if (cur == 0)
			{
				ans = qs[i];
				break;
			}
			dec(board, cur);
			for (k=0; k<9; k++)
			{
				nxt = click(board, k/3, k%3);
				if (used[nxt] != ucnt)
				{
					used[nxt] = ucnt;
					qq[j] = nxt;
					qs[j] = qs[i] + 1;
					j++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
