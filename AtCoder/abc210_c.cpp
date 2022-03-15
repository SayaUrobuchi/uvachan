#include <iostream>
#include <unordered_map>
using namespace std;
using um = unordered_map<int, int>;

int ary[1048576];

int main()
{
	int n, m, i, ans;
	um mp;
	um::iterator it;
	while (scanf("%d%d", &n, &m) == 2)
	{
		mp.clear();
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if (i < m)
			{
				++mp[ary[i]];
			}
		}
		for (i=m, ans=mp.size(); i<n; i++)
		{
			it = mp.find(ary[i-m]);
			if (!(--(it->second)))
			{
				mp.erase(it);
			}
			++mp[ary[i]];
			ans = max(ans, (int)mp.size());
		}
		printf("%d\n", ans);
	}
	return 0;
}
