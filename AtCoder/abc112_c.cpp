#include <iostream>
using namespace std;

const int N = 128;

int px[N], py[N], ph[N];

int main()
{
	int n, i, j, k, x, y, h, maxh, th, ax, ay, ah;
	bool gg, found;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d%d", &px[i], &py[i], &ph[i]);
	}
	for (i=0, found=false; i<=100&&!found; i++)
	{
		for (j=0; j<=100&&!found; j++)
		{
			for (k=0, h=-1, maxh=2e9, gg=false; k<n&&!gg; k++)
			{
				x = abs(px[k]-i);
				y = abs(py[k]-j);
				if (ph[k])
				{
					// ph[k] = h - x - y => h = ph[k] + x + y
					th = ph[k] + x + y;
					if (h != -1 && th != h)
					{
						gg = true;
					}
					h = th;
				}
				else
				{
					// h - x - y <= 0 => h <= x + y
					maxh = min(maxh, x+y);
				}
			}
			if (!gg && h <= maxh)
			{
				if (h != -1 || maxh == 1)
				{
					found = true;
					ax = i;
					ay = j;
					ah = max(h, 1);
				}
			}
		}
	}
	printf("%d %d %d\n", ax, ay, ah);
	return 0;
}