#include <iostream>
using namespace std;

const int M = 1000000007;

int bit[128];
long long ary[128];

int main()
{
	int n, m, i, j, k, t, a, b, c;
	bool val, tar, gg;
	long long ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d%lld", &a, &b, &c, &ary[i]);
			--a, --b, --c;
			bit[i] = ((1<<a) | (1<<b) | (1<<c));
		}
		for (i=0, ans=1; i<60; i++)
		{
			for (j=0, t=0; j<(1<<n); j++)
			{
				for (k=0, gg=false; k<m; k++)
				{
					val = (j & bit[k]);
					tar = (ary[k] & (1LL << i));
					if (val != tar)
					{
						gg = true;
						break;
					}
				}
				if (!gg)
				{
					++t;
				}
			}
			ans = (ans*t) % M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
