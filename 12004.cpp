#include <stdio.h>

int main()
{
	int cas, count, n;
	long long ans;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		ans = (n-1)*(long long)n/2;
		if(ans&1)
		{
			printf("Case %d: %lld/2\n", ++cas, ans);
		}
		else
		{
			printf("Case %d: %lld\n", ++cas, ans>>1);
		}
	}
	return 0;
}
