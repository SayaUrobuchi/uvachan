#include <iostream>

char board[8][8];

int main()
{
	int i, j, c, tx, ty, ans;
	while (scanf("%s", board[0]) == 1)
	{
		for (i=1; i<4; i++)
		{
			scanf("%s", board[i]);
		}
		for (i=0, ans=0; i<4; i++)
		{
			for (j=0; j<4; j++)
			{
				c = board[i][j];
				if (c >= 'A' && c <= 'O')
				{
					c -= 'A';
					tx = (c>>2);
					ty = (c&3);
					ans += std::abs(tx-i) + std::abs(ty-j);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
