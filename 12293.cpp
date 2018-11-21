#include <stdio.h>

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		puts(n&(n+1) ? "Alice" : "Bob");
	}
	return 0;
}
