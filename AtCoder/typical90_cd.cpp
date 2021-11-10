#include <iostream>
using namespace std;

const int M = 1e9+7;

int main()
{
	int i, ans;
	unsigned long long a, b, p, q, t, u, x, y;
	while (scanf("%llu%llu", &a, &b) == 2)
	{
		for (i=1, p=1, q=10, ans=0; p<=b; p*=10, q*=10, i++)
		{
			if (q > a)
			{
				t = max(p, a);
				u = min(q, b+1);
				x = t+(u-1);
				y = (u-t);
				if (x & 1)
				{
					y >>= 1;
				}
				else
				{
					x >>= 1;
				}
				ans = (ans + (x%M)*(y%M)%M*i) % M;
			}
		}
		printf("%llu\n", ans);
	}
	return 0;
}
