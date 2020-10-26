#include <iostream>

int ary[4];
char board[8][1024];
int dx[] = {0, 1, 1, 3, 4, 4, 6};
int dy[] = {2, 1, 5, 2, 1, 5, 2};
const char *key[] = {"xxx.xxx", "..x..x.", "x.xxx.x", "x.xx.xx", ".xxx.x.", "xx.x.xx", "xx.xxxx", "x.x..x.", "xxxxxxx", "xxxx.xx"};
int tbl[1<<8];
char buf[16];

void f0(char *buf, int t)
{
	int i, j, k, c;
	for (i=0; buf[i]; i++)
	{
		if (i)
		{
			putchar('.');
		}
		c = buf[i] - '0';
		if ((key[c][t] == 'x') || (t-2 >= 0 && key[c][t-2] == 'x') || (t+1 < 7 && key[c][t+1] == 'x'))
		{
			putchar('x');
		}
		else
		{
			putchar('.');
		}
		for (j=0; j<3; j++)
		{
			putchar(key[c][t]);
		}
		if ((key[c][t] == 'x') || (t-1 >= 0 && key[c][t-1] == 'x') || (t+2 < 7 && key[c][t+2] == 'x'))
		{
			putchar('x');
		}
		else
		{
			putchar('.');
		}
	}
	puts("");
}

void f1(char *buf, int t, int u)
{
	int i, j, k, c;
	for (k=0; k<2; k++)
	{
		for (i=0; buf[i]; i++)
		{
			if (i)
			{
				putchar('.');
			}
			c = buf[i] - '0';
			putchar(key[c][t]);
			for (j=0; j<3; j++)
			{
				putchar('.');
			}
			putchar(key[c][u]);
		}
		puts("");
	}
}

int main()
{
	int i, j, k, t;
	for (i=0; i<10; i++)
	{
		for (j=0, t=0; j<7; j++)
		{
			t <<= 1;
			if (key[i][j] == 'x')
			{
				++t;
			}
		}
		tbl[t] = i;
	}
	board[0][0] = '.';
	while (scanf("%s", board[0]+1) == 1)
	{
		for (i=1; i<7; i++)
		{
			scanf("%s", board[i]+1);
		}
		for (i=0, j=0, ary[0]=0; board[0][i]; i+=6)
		{
			if (board[1][i+3] == 'x')
			{
				++j;
				ary[j] = 0;
				continue;
			}
			for (k=0, t=0; k<7; k++)
			{
				t = ((t<<1) | (board[dx[k]][i+dy[k]]=='x'?1:0));
			}
			//printf("%d => %d\n", t, tbl[t]);
			ary[j] = ary[j]*10 + tbl[t];
		}
		sprintf(buf, "%d", ary[0]+ary[1]);
		f0(buf, 0);
		f1(buf, 1, 2);
		f0(buf, 3);
		f1(buf, 4, 5);
		f0(buf, 6);
	}
	return 0;
}
