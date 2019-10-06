#include <stdio.h>

void recurs(int n)
{
	int t;
	if (n)
	{
		scanf("%d", &t);
		recurs(n-1);
		printf("%d\n", t);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	recurs(n);
	return 0;
}
