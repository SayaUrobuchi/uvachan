#include <stdio.h>

int main()
{
	int n;
	long long ans;
	while(scanf("%d", &n) == 1)
	{
		n -= n%2;
		ans = (2+n/2);
		ans *= n/2+1;
		ans /= 2;
		printf("%lld\n", ans);
	}
	return 0;
}
