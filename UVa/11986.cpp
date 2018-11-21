#include <stdio.h>

int main()
{
	int count, ans, cas;
	long long n;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%lld", &n);
		ans = 0;
		++n;
		while (n > 1)
		{
			n = ((n+1)>>1);
			++ans;
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
