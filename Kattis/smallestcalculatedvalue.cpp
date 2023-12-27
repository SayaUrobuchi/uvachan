#include <iostream>
using namespace std;

const int NG = -1e9;
const int ADD = 0;
const int SUB = 1;
const int MUL = 2;

int calc(int a, int b, int op)
{
	if (op == ADD)
	{
		return a + b;
	}
	else if (op == SUB)
	{
		return a - b;
	}
	else if (op == MUL)
	{
		return a * b;
	}
	else
	{
		if (b == 0 || a % b)
		{
			return NG;
		}
		return a / b;
	}
}

int main()
{
	int a, b, c, i, j;
	scanf("%d%d%d", &a, &b, &c);
	int best = 1e9;
	for (i=0; i<4; i++)
	{
		int d = calc(a, b, i);
		if (d != NG)
		{
			for (j=0; j<4; j++)
			{
				int e = calc(d, c, j);
				if (e != NG)
				{
					if (e >= 0 && e < best)
					{
						best = e;
					}
				}
			}
		}
	}
	printf("%d\n", best);
	return 0;
}
