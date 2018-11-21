#include <stdio.h>

int main()
{
	int count, n;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		printf("%lld\n", (long long)(n+1)*(n+1)-1LL);
	}
    return 0;
}