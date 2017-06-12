#include <stdio.h>
#include <string.h>

#define MYTURN 0
#define AG1TURN 1
#define AG2TURN 2
#define WIN 1
#define DIE 2
#define NOTHING 3

int used[3][262144];
int dp[3][262144];
int wayx[5] = {0, 1, 0, -1, 0};
int wayy[5] = {1, 0, -1, 0, 0};
int agentx[2], agenty[2];
char map[8][9];

int valid(int x, int y)
{
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int getloc(int x, int y)
{
	return x + (y<<3);
}

int search(int turn, int state)
{
	int i, res, s, x, y, tx, ty, mx, my, agx1, agx2, agy1, agy2, stemp;
	if(used[turn][state])
	{
		return dp[turn][state];
	}
	dp[turn][state] = 0;
	used[turn][state] = 1;
	stemp = state;
	res = 0;
	s = state;
	mx = s % 64;
	my = (mx >> 3);
	mx %= 8;
	s >>= 6;
	agx1 = s % 64;
	agy1 = (agx1 >> 3);
	agx1 %= 8;
	s >>= 6;
	agx2 = s % 64;
	agy2 = (agx2 >> 3);
	agx2 %= 8;
	if(mx == agx1 && my == agy1)
	{
		return dp[turn][state]=DIE;
	}
	else if(mx == agx2 && my == agy2)
	{
		return dp[turn][state]=DIE;
	}
	else if(map[mx][my] == 'P')
	{
		return dp[turn][state]=WIN;
	}
	if(turn == MYTURN)
	{
		state -= state % 64;
		x = mx;
		y = my;
		res = DIE;
		for(i=0; i<5; i++)
		{
			tx = x + wayx[i];
			ty = y + wayy[i];
			if(valid(tx, ty) && map[tx][ty] != '#')
			{
				s = search(AG1TURN, state+getloc(tx, ty));
				if(s == WIN)
				{
					res = WIN;
					break;
				}
				else if(s == DIE)
				{
					if(res != DIE)
					{
						res = 0;
					}
				}
				else
				{
					res = 0;
				}
			}
		}
	}
	else if(turn == AG1TURN)
	{
		state -= (((state>>6) % 64) << 6);
		x = agx1;
		y = agy1;
		res = WIN;
		for(i=0; i<5; i++)
		{
			tx = x + wayx[i];
			ty = y + wayy[i];
			if(valid(tx, ty) && map[tx][ty] != '#')
			{
				s = search(AG2TURN, state+(getloc(tx, ty)<<6));
				if(s == DIE)
				{
					res = DIE;
					break;
				}
				else if(s == WIN)
				{
					if(res != WIN)
					{
						res = 0;
					}
				}
				else
				{
					res = 0;
				}
			}
		}
	}
	else if(turn == AG2TURN)
	{
		state -= ((state>>12) << 12);
		x = agx2;
		y = agy2;
		res = WIN;
		for(i=0; i<5; i++)
		{
			tx = x + wayx[i];
			ty = y + wayy[i];
			if(valid(tx, ty) && map[tx][ty] != '#')
			{
				s = search(MYTURN, state+(getloc(tx, ty)<<12));
				if(s == DIE)
				{
					res = DIE;
					break;
				}
				else if(s == WIN)
				{
					if(res != WIN)
					{
						res = 0;
					}
				}
				else
				{
					res = 0;
				}
			}
		}
	}
	return dp[turn][stemp]=res;
}

int main()
{
	int count, i, j, anum, myx, myy, state, res;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0, anum=0; i<8; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<8; j++)
			{
				if(map[i][j] == 'A')
				{
					agentx[anum] = i;
					agenty[anum++] = j;
				}
				else if(map[i][j] == 'M')
				{
					myx = i;
					myy = j;
				}
			}
		}
		memset(used, 0, sizeof(used));
		memset(dp, 0, sizeof(dp));
		state = getloc(myx, myy) + (getloc(agentx[0], agenty[0])<<6) + (getloc(agentx[1], agenty[1])<<12);
		res = search(MYTURN, state);
		if(res == WIN)
		{
			printf("You can escape.\n");
		}
		else if(res == DIE)
		{
			printf("You are eliminated.\n");
		}
		else
		{
			printf("You are trapped in the Matrix.\n");
		}
	}
	return 0;
}
