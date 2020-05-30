#include <stdio.h>

char board[32][32];

int main()
{
	int n, i, j, k, t, u, gg;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		for (i=0, gg=0; i<n&&!gg; i++)
		{
			for (j=0, t=0, u=0; j<n&&!gg; j++)
			{
				k = (board[i][j] == 'B' ? 1 : -1);
				u += k;
				if (t*k < 0)
				{
					t = 0;
				}
				t += k;
				if (t <= -3 || t >= 3)
				{
					gg = 1;
				}
			}
			if (u)
			{
				gg = 1;
			}
			for (j=0, t=0, u=0; j<n&&!gg; j++)
			{
				k = (board[j][i] == 'B' ? 1 : -1);
				u += k;
				if (t*k < 0)
				{
					t = 0;
				}
				t += k;
				if (t <= -3 || t >= 3)
				{
					gg = 1;
				}
			}
			if (u)
			{
				gg = 1;
			}
		}
		puts(gg?"0":"1");
	}
	return 0;
}
