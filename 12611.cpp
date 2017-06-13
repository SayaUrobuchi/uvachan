#include <stdio.h>

int main()
{
	int cas, count, n, h, w, l, r;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		h = n*3/2;
		w = n*5;
		l = -w*9/20;
		r = w*11/20;
		printf("Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n", ++cas, l, h, r, h, r, -h, l, -h);
	}
	return 0;
}
