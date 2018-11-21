#include <stdio.h>

unsigned long long ary[1000005];

int main()
{
	int n, i;
	unsigned long long total, ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=0, total=0; i<n; i++)
		{
			scanf("%llu", &ary[i]);
			total += ary[i];
		}
		total /= n;
		for(i=0, ans=0; i<n; i++)
		{
			if(ary[i] > total)
			{
				ans += ary[i] - total;
			}
		}
		printf("%llu\n", ans);
	}
	return 0;
}
