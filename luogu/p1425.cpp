#include <stdio.h>

int main()
{
	int a, b, c, d, e;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	e = c*60+d-a*60-b;
	printf("%d %d\n", e/60, e%60);
	return 0;
}
