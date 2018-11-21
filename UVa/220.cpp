#include <stdio.h>
#include <string.h>

#define EMPTY 0
#define BLACK 1
#define WHITE 2

int hash[128];
int wayx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int wayy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int qx[80], qy[80];
char board[8][9], chess[4]={"-BW"};
char buf[2008];

int valid(int x, int y)
{
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main()
{
	int count, i, j, k, q, b, w, c, f, x, y, tx, ty, turn;
	hash['-'] = EMPTY;
	hash['W'] = WHITE;
	hash['B'] = BLACK;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0, b=w=0; i<8; i++)
		{
			scanf("%s", board[i]);
			for(j=0; j<8; j++)
			{
				if(board[i][j] == 'W')
				{
					w++;
				}
				else if(board[i][j] == 'B')
				{
					b++;
				}
			}
		}
		scanf("%s", buf);
		turn = hash[buf[0]];
		while(scanf("%s", buf) == 1)
		{
			if(!strcmp(buf, "Q"))
			{
				for(i=0; i<8; i++)
				{
					puts(board[i]);
				}
				break;
			}
			else if(!strcmp(buf, "L"))
			{
				for(i=0, q=0; i<8; i++)
				{
					for(j=0; j<8; j++)
					{
						if(board[i][j] == '-')
						{
							for(k=0; k<8; k++)
							{
								for(x=i, y=j, c=0; ; )
								{
									x += wayx[k];
									y += wayy[k];
									if(valid(x, y))
									{
										if(hash[board[x][y]] == EMPTY)
										{
											c = 0;
											break;
										}
										else if(hash[board[x][y]] == turn)
										{
											break;
										}
										c++;
									}
									else
									{
										c = 0;
										break;
									}
								}
								if(c)
								{
									break;
								}
							}
							if(k < 8)
							{
								qx[q] = i+1;
								qy[q] = j+1;
								q++;
							}
						}
					}
				}
				if(q)
				{
					printf("(%d,%d)", qx[0], qy[0]);
					for(i=1; i<q; i++)
					{
						printf(" (%d,%d)", qx[i], qy[i]);
					}
					printf("\n");
				}
				else
				{
					printf("No legal move.\n");
				}
			}
			else
			{
				x = buf[1] - '1';
				y = buf[2] - '1';
				for(f=0; ; turn=3-turn)
				{
					for(k=0; k<8; k++)
					{
						for(tx=x, ty=y, c=0; ; )
						{
							tx += wayx[k];
							ty += wayy[k];
							if(valid(tx, ty))
							{
								if(board[tx][ty] == '-')
								{
									c = 0;
									break;
								}
								else if(hash[board[tx][ty]] == turn)
								{
									break;
								}
								qx[c] = tx;
								qy[c] = ty;
								c++;
							}
							else
							{
								c = 0;
								break;
							}
						}
						if(c)
						{
							f = 1;
							for(i=0; i<c; i++)
							{
								/*printf("XDD %d %d %c\n", qx[i], qy[i], chess[turn]);*/
								board[qx[i]][qy[i]] = chess[turn];
								if(turn == BLACK)
								{
									b++;
									w--;
								}
								else
								{
									b--;
									w++;
								}
							}
						}
					}
					if(f)
					{
						if(turn == BLACK)
						{
							b++;
						}
						else
						{
							w++;
						}
						board[x][y] = chess[turn];
						turn = 3 - turn;
						break;
					}
				}
				printf("Black - %2d White - %2d\n", b, w);
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
