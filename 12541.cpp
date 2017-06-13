#include <stdio.h>

char nam[128][32];

int main()
{
	int n, i, p, q, r, y, oy, yy;
	char *op, *yp;
	scanf("%d", &n);
	oy = 0;
	yy = 2147483647;
	for (i=0; i<n; i++)
	{
		scanf("%s%d%d%d", nam[i], &p, &q, &r);
		y = p + q*128 + r*16384;
		if (y > oy)
		{
			oy = y;
			op = nam[i];
		}
		if (y < yy)
		{
			yy = y;
			yp = nam[i];
		}
	}
	puts(op);
	puts(yp);
	return 0;
}
