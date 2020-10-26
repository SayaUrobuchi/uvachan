#include <iostream>

int tbl[16];

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		++tbl[a];
		++tbl[b];
		++tbl[c];
		if (tbl[5] == 2 && tbl[7] == 1)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
		--tbl[a];
		--tbl[b];
		--tbl[c];
	}
	return 0;
}
