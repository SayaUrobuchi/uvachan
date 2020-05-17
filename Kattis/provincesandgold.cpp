#include <stdio.h>

const char *vs[] = {"", "Estate", "Duchy", "Province"};
const char *ws[] = {"Copper", "Silver", "Gold"};

int main()
{
	int a, b, c, n, v, w;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		n = a*3 + b*2 + c;
		v = (n+1)/3;
		if (v > 3)
		{
			v = 3;
		}
		w = n/3;
		if (w > 2)
		{
			w = 2;
		}
		if (v)
		{
			printf("%s or %s\n", vs[v], ws[w]);
		}
		else
		{
			puts(ws[w]);
		}
	}
	return 0;
}
