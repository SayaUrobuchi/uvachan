#include <stdio.h>
#include <string.h>

char check(int x, int y)
{
	if(x < 8 && x > -1 && y < 8 && y > -1) return 1;
	return 0;
}

int main()
{
	char i, j, k, queue[64][3], targetx, targety, board[8][8], buf[3], buf2[3], x, y, z;
	char walk[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-2, 1}};
	while(scanf("%s%s", buf, buf2) == 2)
	{
		memset(board, 1, sizeof(board));
		queue[0][0] = buf[0] - 97;
		queue[0][1] = buf[1] - 49;
		queue[0][2] = 0;
		targetx = buf2[0] - 97;
		targety = buf2[1] - 49;
		if(targetx == queue[0][0] && targety == queue[0][1])
		{
			printf("To get from %s to %s takes 0 knight moves.\n", buf, buf2);
			continue;
		}
		for(i=0, j=1; i<j; i++)
		{
			x = queue[i][0];
			y = queue[i][1];
			z = queue[i][2] + 1;
			for(k=0; k<8; k++)
			{
				if(check(x + walk[k][0], y + walk[k][1]) && board[x + walk[k][0]][y + walk[k][1]])
				{
					if(targetx == x + walk[k][0] && targety == y + walk[k][1]) break;
					board[x + walk[k][0]][y + walk[k][1]] = 0;
					queue[j][0] = x + walk[k][0];
					queue[j][1] = y + walk[k][1];
					queue[j++][2] = z;
				}
			}
			if(k < 8) break;
		}
		printf("To get from %s to %s takes %d knight moves.\n", buf, buf2, z);
	}
	return 0;
}
