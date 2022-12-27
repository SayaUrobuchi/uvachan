#include <iostream>
#include <set>
using namespace std;
using pp = pair<int, int>;

int main()
{
	int n, i, a, b, ans;
	while (scanf("%d", &n) == 1)
	{
		set<pp> se;
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			se.emplace(a, b);
		}
		ans = 0;
		for (auto it=se.begin(); it!=se.end(); ++it)
		{
			for (auto iu=se.begin(); iu!=it; ++iu)
			{
				if (iu->first != it->first && iu->second != it->second)
				{
					if (se.count({iu->first, it->second}) && se.count({it->first, iu->second}))
					{
						++ans;
					}
				}
			}
		}
		printf("%d\n", ans>>1);
	}
	return 0;
}

