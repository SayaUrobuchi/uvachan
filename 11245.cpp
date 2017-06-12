#include <stdio.h>

long long n, ans, times;

int main()
{
	int count, m;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lld%d", &n, &m);
		ans = n--;
		for(n/=m-1, times=1; n; times*=m, n/=m-1)
		{
			ans += n * times;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
