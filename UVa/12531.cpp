#include <stdio.h>

int tbl[512];

int main()
{
	int i, h, m, a, n;
	for (i=0; i<720; i++)
	{
		h = 6 * (i / 12);
		m = 6 * (i%60);
		a = (360+h-m)%360;
		tbl[a] = 1;
		tbl[360-a] = 1;
	}
	while (scanf("%d", &n) == 1)
	{
		puts(tbl[n] ? "Y" : "N");
	}
	return 0;
}
