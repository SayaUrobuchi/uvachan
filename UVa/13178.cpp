#include <stdio.h>

int main()
{
	int count, n;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		puts(n%3 == 1 ? "NO" : "YES");
	}
	return 0;
}
