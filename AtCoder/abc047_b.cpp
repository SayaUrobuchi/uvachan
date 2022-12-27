#include <iostream>
using namespace std;

int main()
{
	int n, m, o, i, x0, x1, y0, y1, x, y, cmd;
	scanf("%d%d", &n, &m);
	scanf("%d", &o);
	x0 = 0;
	x1 = n;
	y0 = 0;
	y1 = m;
	for (i=0; i<o; i++)
	{
		scanf("%d%d%d", &x, &y, &cmd);
		if (cmd == 1)
		{
			x0 = max(x0, x);
		}
		else if (cmd == 2)
		{
			x1 = min(x1, x);
		}
		else if (cmd == 3)
		{
			y0 = max(y0, y);
		}
		else
		{
			y1 = min(y1, y);
		}
	}
	printf("%d\n", max(0, x1-x0)*max(0, y1-y0));
	return 0;
}