#include <stdio.h>

int main()
{
	long long n, m;
	int i;
	while (scanf("%lld%lld", &n, &m) == 2)
	{
		for (i=1; n%m; m-=n%m, i++);
		printf("%d\n", i);
	}
	return 0;
}
