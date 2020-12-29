#include <iostream>

int main()
{
	int n;
	long long t;
	while (scanf("%d", &n) == 1)
	{
		t = ((n+1)>>1);
		printf("%lld\n", (1+t)*t+(n&1?0:t+1));
	}
	return 0;
}
