#include <iostream>

int px[4], py[4];

int main()
{
	int i, x0, y0, x1, y1;
	while (scanf("%d%d", &px[0], &py[0]) == 2)
	{
		for (i=1; i<3; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		for (i=0; i<3; i++)
		{
			x0 = px[i] - px[(i+2)%3];
			y0 = py[i] - py[(i+2)%3];
			x1 = px[(i+1)%3] - px[i];
			y1 = py[(i+1)%3] - py[i];
			if (x0*x1 + y0*y1 == 0)
			{
				break;
			}
		}
		printf("%d %d\n", px[(i+1)%3]-x0, py[(i+1)%3]-y0);
	}
	return 0;
}
