#include <stdio.h>

int main()
{
	long n, i, cas, last, tmp;
	long long ans;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		for(i=2, last=n / 2, ans=0; i<last; i++)
		{
			ans += (n - n % i) - i;
			tmp = n / (i + 1);
			ans += (long long)(last + tmp + 1) * (last - tmp) / 2 * (i - 1);
			last = tmp;
		}
		if(i == last)
		{
			ans += last * i - last;
		}
		printf("Case %d: %lld\n", ++cas, ans);
	}
	return 0;
}
