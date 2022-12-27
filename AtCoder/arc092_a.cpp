#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int N = 128;

pp red[N], blue[N];

int main()
{
	int n, i, j, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &red[i].first, &red[i].second);
	}
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &blue[i].first, &blue[i].second);
	}
	sort(red, red+n);
	sort(blue, blue+n);
	set<pp> se;
	for (i=0, j=0, ans=0; i<n; i++)
	{
		for (; j<n&&red[j].first<blue[i].first; j++)
		{
			se.emplace(red[j].second, j);
		}
		auto it = se.lower_bound({blue[i].second, -1});
		if (it != se.begin())
		{
			++ans;
			--it;
			se.erase(it);
		}
	}
	printf("%d\n", ans);
	return 0;
}