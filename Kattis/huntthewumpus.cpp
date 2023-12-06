#include <iostream>
using namespace std;

const int NONE = -1;

int ary[4];
bool used[105];

int adv(int &s)
{
	s += s/13 + 15;
	return s % 100;
}

int main()
{
	int seed, i, x, y;
	scanf("%d", &seed);
	for (i=0; i<4; i++)
	{
		int res;
		while (res = adv(seed))
		{
			if (!used[res])
			{
				used[res] = true;
				break;
			}
		}
		ary[i] = res;
	}
	int alive = 4;
	int moves = 0;
	while (scanf("%1d%1d", &x, &y) == 2)
	{
		++moves;
		int hit, best;
		for (i=0, hit=NONE, best=1e9; i<4; i++)
		{
			if (ary[i] != NONE)
			{
				if (ary[i] == x*10 + y)
				{
					hit = i;
				}
				else
				{
					best = min(best, abs(ary[i]/10 - x) + abs(ary[i]%10 - y));
				}
			}
		}
		if (hit != NONE)
		{
			puts("You hit a wumpus!");
			ary[hit] = NONE;
			--alive;
		}
		if (alive)
		{
			printf("%d\n", best);
		}
		else
		{
			printf("Your score is %d moves.\n", moves);
		}
	}
	return 0;
}
