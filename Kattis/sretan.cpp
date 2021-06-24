#include <iostream>

void recurs(int n, int d)
{
	if (!d)
	{
		return;
	}
	recurs(n>>1, d-1);
	printf("%d", (n&1)?7:4);
}

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		for (i=1, --n; n>=(1LL<<i); n-=(1LL<<i), i++);
		recurs(n, i);
		puts("");
	}
	return 0;
}
