#include <iostream>
#include <unordered_map>
using namespace std;
using mm = unordered_map<string, int>;

char s[1048576];

int main()
{
	int n, i, ans;
	mm tbl;
	while (scanf("%d", &n) == 1)
	{
		tbl.clear();
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			++tbl[s];
		}
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%s", s);
			mm::iterator it = tbl.find(s);
			if (it != tbl.end() && it->second)
			{
				--(it->second);
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
