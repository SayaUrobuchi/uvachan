#include <iostream>

double x0[1024], y0[1024], x1[1024], y1[1024];
char nam[1024][1024], buf[1024];

int main()
{
	int n, m, i, j;
	double x, y;
	bool first = true;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%lf%lf%lf%lf%s", &x0[i], &y0[i], &x1[i], &y1[i], nam[i]);
		}
		scanf("%d", &m);
		if (!first)
		{
			puts("");
		}
		first = false;
		for (i=0; i<m; i++)
		{
			scanf("%lf%lf%s", &x, &y, buf);
			for (j=0; j<n; j++)
			{
				if (x >= x0[j] && x <= x1[j] && y >= y0[j] && y <= y1[j])
				{
					break;
				}
			}
			printf("%s %s\n", buf, (j==n?"floor":(*nam[j]==*buf?"correct":nam[j])));
		}
	}
	return 0;
}
