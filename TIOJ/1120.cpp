#include <stdio.h>

int main()
{
	int n, x, y;
	while(scanf("%d", &n) == 1)
	{
		n = n*6 % 40;
		for(x=10, y=5; x<15&&n; x++, n--);
		for(; y<15&&n; y++, n--);
		for(; x>5&&n; x--, n--);
		for(; y>5&&n; y--, n--);
		for(; x<10&&n; x++, n--);
		printf("(%d,%d)\n", x, y);
	}
	return 0;
}
