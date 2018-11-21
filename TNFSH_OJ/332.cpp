#include <stdio.h>

#define M 100000007

int main()
{
	int n, m, i, t;
	long long p, q, r, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, q=1; i<n; i++)
		{
			scanf("%d", &t);
			q = (q*t) % M;
		}
		for (i=0, p=1; i<m; i++)
		{
			scanf("%d", &t);
			p = (p*t) % M;
		}
		for (i=0, r=p, ans=1; (1<<i)<=n; i++, r=(r*r)%M)
		{
			if (n & (1<<i))
			{
				ans = (ans*r) % M;
			}
		}
		for (i=0, r=q; (1<<i)<=m; i++, r=(r*r)%M)
		{
			if (m & (1<<i))
			{
				ans = (ans*r) % M;
			}
		}
		printf("%lld\n", (ans+M)%M);
	}
	return 0;
}
