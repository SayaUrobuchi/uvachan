#include <iostream>
using namespace std;

const int N = 100005;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};

int tbl[128];
char buf[N];

int main()
{
	int t, i;
	tbl['R'] = 0;
	tbl['D'] = 1;
	tbl['L'] = 2;
	tbl['U'] = 3;
	scanf("%s%d", buf, &t);
	int unknown = 0;
	int x = 0;
	int y = 0;
	for (i=0; buf[i]; i++)
	{
		if (buf[i] == '?')
		{
			++unknown;
		}
		else
		{
			int dir = tbl[buf[i]];
			x += DX[dir];
			y += DY[dir];
		}
	}
	int d = abs(x) + abs(y);
	if (t == 1)
	{
		printf("%d\n", d + unknown);
	}
	else
	{
		int f = min(d, unknown);
		d -= f;
		unknown -= f;
		if (unknown > 0)
		{
			d = unknown % 2;
		}
		printf("%d\n", d);
	}
	return 0;
}
