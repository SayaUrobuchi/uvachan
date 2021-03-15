#include<iostream>
using namespace std;

int main()
{
	int n, i, x, y, t, lx, ly, best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, best=0; i<n; i++)
		{
			scanf("%d%d", &x, &y);
			if (i)
			{
				t = (y-ly)/(x-lx);
				if (t > best)
				{
					best = t;
				}
			}
			lx = x;
			ly = y;
		}
		printf("%d\n", best);
	}
	return 0;
}
