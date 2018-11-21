#include <stdio.h>

int main()
{
	int count, n, k, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &k);
		for(ans=0; n; n/=k)
		{
			ans += n - n/k;
			n /= k;
		}
		printf("%d\n", ans);
	}
	return 0;
}
