#include <iostream>
#include <cmath>

int main()
{
	int count, n, i, d, sc, ans, x, y;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d%d", &x, &y);
			d = (int)(ceil(sqrt(x*x + y*y))+1e-9);
			sc = 11 - ((d-1)/20+1);
			if (sc < 0)
			{
				sc = 0;
			}
			//printf("%d => %d\n", d, sc);
			ans += sc;
		}
		printf("%d\n", ans);
	}
	return 0;
}
