#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n, m, i, t;
	long long ans, sum;
	while (scanf("%d%d", &n, &m) == 2)
	{
		map<long long, int> mp;
		mp[0] = 1;
		for (i=0, ans=0, sum=0; i<n; i++)
		{
			scanf("%d", &t);
			sum += t;
			auto it = mp.find(sum-m);
			if (it != mp.end())
			{
				ans += it->second;
			}
			++mp[sum];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

