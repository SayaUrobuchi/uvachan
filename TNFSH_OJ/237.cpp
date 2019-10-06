#include <stdio.h>

int main()
{
	int a1, a2, a3, b1, b2, b3, c1, c2, c3;
	scanf("%d%d%d", &a1, &a2, &a3);
	scanf("%d%d%d", &b1, &b2, &b3);
	scanf("%d%d%d", &c1, &c2, &c3);
	printf("4 %d\n", (a1+a2+a3)-((a1+a3+b1+b3+c1+c3)>>1));
	return 0;
}
