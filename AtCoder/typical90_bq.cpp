#include <iostream>
using namespace std;

const int M = 1e9+7;

int main()
{
	int m;
	long long n, t, ans;
	while (scanf("%lld%d", &n, &m) == 2)
	{
		ans = m;
		if (n >= 2)
		{
			ans = (ans*(m-1)) % M;
		}
		if (n >= 3)
		{
			m = max(0, m-2);
			for (n-=2, t=m%M; n; n>>=1, t=(t*t)%M)
			{
				if (n & 1)
				{
					ans = (ans*t) % M;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
