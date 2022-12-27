#include <iostream>
#include <cmath>
using namespace std;

int tbl[200005];

int main()
{
	int n, i, j, k, p, t;
	long long ans;
	for (i=3; i*i<=200000; i+=2)
	{
		if (!tbl[i])
		{
			for (j=i*i, k=(i<<1); j<=200000; j+=k)
			{
				tbl[j] = i;
			}
		}
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=1, ans=0; i<=n; i++)
		{
			for (j=i, t=1; j>1; )
			{
				if (j & 1)
				{
					p = tbl[j];
					if (p == 0)
					{
						p = j;
					}
				}
				else
				{
					p = 2;
				}
				for (k=0; j%p==0; j/=p, ++k);
				if (k & 1)
				{
					t *= p;
				}
			}
			if (t <= n)
			{
				ans += (int)(sqrt(n/t)+1e-7);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

