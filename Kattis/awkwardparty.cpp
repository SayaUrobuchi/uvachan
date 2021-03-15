#include <iostream>
#include <unordered_map>
using um = std::unordered_map<int, int>;

int main()
{
	int n, i, t, ans;
	um tbl;
	um::iterator it;
	while (scanf("%d", &n) == 1)
	{
		tbl.clear();
		for (i=0, ans=n; i<n; i++)
		{
			scanf("%d", &t);
			it = tbl.find(t);
			if (it == tbl.end())
			{
				tbl[t] = i;
			}
			else
			{
				ans = std::min(ans, i-it->second);
				it->second = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
