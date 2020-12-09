#include <iostream>

int main()
{
	int n, i, best, w, h, j, m, bb, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=1, best=n+2, w=1, h=1; i*i*i<=n; i++)
		{
			if (n % i == 0)
			{
				for (j=2, m=n/i, bb=m+1, t=1; j*j<=m; j++)
				{
					if (m % j == 0)
					{
						t = j;
						bb = j + m/j;
					}
				}
				if (w+bb < best)
				{
					best = i+bb;
					w = i;
					h = t;
				}
			}
		}
		//printf("%d %d %d\n", w, h, n/w/h);
		t = n/w/h;
		printf("%d\n", (w*t+t*h+w*h)<<1);
	}
	return 0;
}
