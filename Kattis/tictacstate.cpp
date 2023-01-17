#include <iostream>
using namespace std;

const int X = 1;
const int O = 0;
const int NONE = -1;
const int MSK = 0b111111111;

bool isset(int n, int x, int y)
{
	return n & (1 << (x*3+y));
}

bool getbit(int n, int x, int y)
{
	return n & (1 << (x*3+y+9));
}

int judge(int n)
{
	int i, j;
	for (i=0; i<3; i++)
	{
		if (isset(n, i, 0) && isset(n, i, 1) && isset(n, i, 2)
		 && getbit(n, i, 0) == getbit(n, i, 1) && getbit(n, i, 1) == getbit(n, i, 2))
		{
			return getbit(n, i, 0);
		}
		if (isset(n, 0, i) && isset(n, 1, i) && isset(n, 2, i)
		 && getbit(n, 0, i) == getbit(n, 1, i) && getbit(n, 1, i) == getbit(n, 2, i))
		{
			return getbit(n, 0, i);
		}
	}
	if (isset(n, 0, 0) && isset(n, 1, 1) && isset(n, 2, 2)
	 && getbit(n, 0, 0) == getbit(n, 1, 1) && getbit(n, 1, 1) == getbit(n, 2, 2))
	{
		return getbit(n, 0, 0);
	}
	if (isset(n, 2, 0) && isset(n, 1, 1) && isset(n, 0, 2)
	 && getbit(n, 2, 0) == getbit(n, 1, 1) && getbit(n, 1, 1) == getbit(n, 0, 2))
	{
		return getbit(n, 2, 0);
	}
	return NONE;
}

int main()
{
	int count, n, winner;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%o", &n);
		winner = judge(n);
		if (winner == O)
		{
			puts("O wins");
		}
		else if (winner == X)
		{
			puts("X wins");
		}
		else
		{
			if ((n & MSK) == MSK)
			{
				puts("Cat's");
			}
			else
			{
				puts("In progress");
			}
		}
	}
	return 0;
}
