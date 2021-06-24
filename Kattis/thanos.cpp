#include <iostream>

int main()
{
	int count, b, c, i;
	long long a;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%lld%d%d", &a, &b, &c);
		for (i=0; a<=c; ++i, a*=b);
		printf("%d\n", i);
	}
	return 0;
}
