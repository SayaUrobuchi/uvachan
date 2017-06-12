#include <stdio.h>

int main()
{
	int cas, n, i, lim, p, q;
	long long ans;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=1, lim=n/3, ans=0; i<lim; i++)
		{
			p = i+1;
			q = (n-i-1) / 2;
			if(n - q <= q)
			{
				q--;
			}
			if(q >= p)
			{
				ans += q-p+1;
			}
		}
		printf("Case %d: %lld\n", ++cas, ans);
	}
	return 0;
}
