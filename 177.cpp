#include <stdio.h>
#include <string.h>

#define N 350

int x, y, dir;
int wayx[4] = {0, -1, 0, 1};
int wayy[4] = {1, 0, -1, 0};
int line[4];
char board[N][N];

void adjust()
{
	if(dir < 0)
	{
		dir += 4;
	}
	if(dir >= 4)
	{
		dir -= 4;
	}
}

void recursion(int n, int r)
{
	if(n)
	{
		recursion(n-1, 0);
		/*if(r)
		{
			printf("R", n);
		}
		else
		{
			printf("L", n);
		}*/
		if(r)
		{
			dir--;
			adjust();
			if(dir == 3)
			{
				 x += wayx[dir];
				 y += wayy[dir];
			}
		}
		else
		{
			dir++;
			adjust();
			if(dir == 3)
			{
				x += wayx[dir];
				y += wayy[dir];
			}
		}
		/*x += wayx[dir];
		y += wayy[dir];*/
		recursion(n-1, 1);
	}
	else
	{
		/*printf("%d %d\n", x, y);*/
		if(dir == 0 || dir == 2)
		{
			x += wayx[dir];
			y += wayy[dir];
		}
		board[x][y] = line[dir];
		if(dir != 3)
		{
			x += wayx[dir];
			y += wayy[dir];
		}
	}
}

void print()
{
	int i, j, min;
	for(i=0, min=N+1; i<N; i++)
	{
		for(j=N-1; j>=0&&board[i][j]==' '; j--);
		board[i][j+1] = 0;
		if(j != -1)
		{
			for(j=0; board[i][j]==' '; j++);
			if(j < min)
			{
				min = j;
			}
		}
	}
	for(i=0; i<N; i++)
	{
		if(board[i][0])
		{
			puts(board[i]+min);
		}
	}
	puts("^");
}

int main()
{
	int n;
	line[0] = line[2] = '_';
	line[1] = line[3] = '|';
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(board, ' ', sizeof(board));
		x = y = N/2;
		dir = 0;
		recursion(n, 0);
		print();
	}
	return 0;
}
