#include <stdio.h>

int main()
{
	int count, n, i;
	long long ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=1, ans=0; n/i>=i; i++)
		{
			ans += (n/i>i?(long long)(n/i):0) + (long long)(n/i-n/(i+1))*i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
