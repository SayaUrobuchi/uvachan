#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> ary[200005];

int main()
{
	int n, i, work;
	bool gg;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i].second, &ary[i].first);
	}
	sort(ary, ary+n);
	for (i=0, work=0, gg=false; i<n&&!gg; i++)
	{
		work += ary[i].second;
		if (work > ary[i].first)
		{
			gg = true;
		}
	}
	if (gg)
	{
		puts("No");
	}
	else
	{
		puts("Yes");
	}
	return 0;
}