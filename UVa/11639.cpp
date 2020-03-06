#include <stdio.h>

int main()
{
	int count, cas, x0, x1, x2, x3, xx0, xx1, y0, y1, y2, y3, yy0, yy1, a, b, c;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d%d%d%d%d%d", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3);
		a = 10000;
		b = (x1-x0) * (y1-y0) + (x3-x2) * (y3-y2);
		xx0 = (x0 > x2 ? x0 : x2);
		xx1 = (x1 < x3 ? x1 : x3);
		yy0 = (y0 > y2 ? y0 : y2);
		yy1 = (y1 < y3 ? y1 : y3);
		c = (xx1 > xx0 ? xx1-xx0 : 0) * (yy1 > yy0 ? yy1-yy0 : 0);
		printf("Night %d: %d %d %d\n", ++cas, c, b-(c<<1), a-b+c);
	}
	return 0;
}
