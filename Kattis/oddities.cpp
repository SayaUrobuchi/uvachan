#include <stdio.h>

int main()
{
	int count, n;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		printf("%d is %s\n", n, (n&1)?"odd":"even");
	}
	return 0;
}
