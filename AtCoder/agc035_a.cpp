#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	map<int, int> mp;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t)
		{
			++mp[t];
		}
	}
	bool yes = false;
	if (mp.empty())
	{
		yes = true;
	}
	else if (mp.size() == 1 && (mp.begin())->second * 3 == n * 2)
	{
		yes = true;
	}
	else if (mp.size() == 3)
	{
		int ret = 0;
		bool ok = true;
		for (decltype(mp)::iterator it=mp.begin(); it!=mp.end(); ++it)
		{
			ret ^= it->first;
			if (it->second * 3 != n)
			{
				ok = false;
			}
		}
		yes = (ok && !ret);
	}
	puts(yes ? "Yes" : "No");
	return 0;
}
