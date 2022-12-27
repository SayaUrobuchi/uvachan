#include <iostream>
#include <map>
using namespace std;

int ary[262144];

int main()
{
	int n, m, i, j;
	long long ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		map<int, int> mp;
		for (i=0, j=0, ans=0; i<n; i++)
		{
			for (; j<n&&mp.size()<=m; j++)
			{
				++mp[ary[j]];
				if (mp.size() > m)
				{
					mp.erase(mp.find(ary[j]));
					break;
				}
			}
			ans += j-i;
			auto it = mp.find(ary[i]);
			if (!(--it->second))
			{
				mp.erase(it);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

