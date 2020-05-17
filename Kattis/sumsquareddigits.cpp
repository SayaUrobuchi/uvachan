#include <stdio.h>

int main()
{
	int count, cas, b, ans;
	long long n, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%lld", &cas, &b, &n);
		for (t=n, ans=0; t; t/=b)
		{
			ans += (t%b)*(t%b);
		}
		printf("%d %d\n", cas, ans);
	}
	return 0;
}
