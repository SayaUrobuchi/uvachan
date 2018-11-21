#include <stdio.h>

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c) == 3)
	{
		printf("%d\n", max(a, max(b, c)));
	}
	return 0;
}
