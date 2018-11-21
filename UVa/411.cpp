#include <stdio.h>
#include <string.h>

#define N 30

int wayx[4] = {1, 0, -1, 0};
int wayy[4] = {0, -1, 0, 1};
int used[35][35];
char map[35][70];
char buf[1005];

struct data
{
	int dir, len;
	int px[35], py[35];
};

struct data centipede[15];

int valid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

int canmove(int n, int x, int y)
{
	return valid(x, y) && map[x][3+y+y] == '.' && !(used[x][y] - (1<<n));
}

int decode(char now)
{
	if(now == 'U')
	{
		return 0;
	}
	else if(now == 'L')
	{
		return 1;
	}
	else if(now == 'D')
	{
		return 2;
	}
	return 3;
}

int main()
{
	int n, i, j, x, y, temp, flag;
	int *px, *py;
	struct data now;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<N; i++)
		{
			sprintf(map[i], "%02d . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\0", i);
		}
		memset(used, 0, sizeof(used));
		for(i=0; i<n; i++)
		{
			scanf("%s%d%d%d", buf, &centipede[i].len, &y, &x);
			temp = centipede[i].dir = decode(buf[0]);
			temp += 2;
			if(temp >= 4)
			{
				temp -= 4;
			}
			px = centipede[i].px;
			py = centipede[i].py;
			for(j=0; j<centipede[i].len; j++)
			{
				px[j] = x;
				py[j] = y;
				if(valid(px[j], py[j]))
				{
					if(used[px[j]][py[j]])
					{
						map[px[j]][3+py[j]+py[j]] = 'X';
					}
					used[px[j]][py[j]] |= 1<<i;
				}
				x += wayx[temp];
				y += wayy[temp];
			}
		}
		for(; ; )
		{
			flag = 1;
			for(i=0; i<n; i++)
			{
				now = centipede[i];
				px = centipede[i].px;
				py = centipede[i].py;
				for(j=0; j<now.len; j++)
				{
					if(canmove(i, px[j], py[j]))
					{
						if(valid(px[j], py[j]))
						{
							used[px[j]][py[j]] -= 1<<i;
						}
						flag = 0;
						px[j] += wayx[now.dir];
						py[j] += wayy[now.dir];
						if(valid(px[j], py[j]))
						{
							if(used[px[j]][py[j]])
							{
								map[px[j]][3+py[j]+py[j]] = 'X';
							}
							used[px[j]][py[j]] |= 1<<i;
						}
					}
				}
			}
			if(flag)
			{
				break;
			}
		}
		puts("   0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2");
		puts("   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9");
		for(i=N-1; i>=0; i--)
		{
			puts(map[i]);
		}
		puts("");
	}
	return 0;
}
