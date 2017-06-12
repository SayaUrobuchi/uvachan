#include <stdio.h>

int main()
{
	int count, p, q, r, i, j, k, gameover;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &p, &q, &r);
		gameover = 0;
		/* neg neg pos */
		for (i=-99; i<0; i++)
		{
			if (i*i < r && q % i == 0)
			{
				for (j=q/i; j<0; j++)
				{
					k = p-i-j;
					if (i != j && k*k+i*i+j*j == r && i*j*k == q)
					{
						gameover = 1;
						break;
					}
				}
				if (gameover)
				{
					break;
				}
			}
		}
		if (!gameover)
		{
			/* pos pos pos */
			for (i=1; i+i+i<=p&&i*i*i<=q&&i*i*3<=r; i++)
			{
				for (j=i+1; i+j+j<=p&&i*j*j<=q&&i*i+j*j*2<=r; j++)
				{
					k = p-i-j;
					if (k != j && i*j*k == q && i*i+j*j+k*k == r)
					{
						gameover = 1;
						break;
					}
				}
				if (gameover)
				{
					break;
				}
			}
		}
		printf(gameover?"%d %d %d\n":"No solution.\n", i, j, k);
	}
	return 0;
}
