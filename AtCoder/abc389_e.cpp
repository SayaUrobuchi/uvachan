#include <iostream>
#include <vector>
using namespace std;

long long calc(long long t)
{
	long long res = (t + 1) / 2;
	return res;
}

int main()
{
	int n, i;
	long long m;
	scanf("%d%lld", &n, &m);
	vector<int> price(n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &price[i]);
	}
	long long l = 1;
	long long r = m;
	long long res, ans;
	while (l <= r)
	{
		long long mid = ((l + r) >> 1);
		long long buy = 0;
		long long sum = 0;
		for (i=0; i<n&&sum<=m; i++)
		{
			long long t = mid / price[i];
			long long c = calc(t);
			if (c && c > (m / price[i]) / c)
			{
				sum = m + 1;
				break;
			}
			sum += c * c * price[i];
			buy += c;
		}
		if (sum <= m)
		{
			ans = buy + (m - sum) / (mid + 1);
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
