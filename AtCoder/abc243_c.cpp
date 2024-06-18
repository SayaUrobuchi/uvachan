#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<pp, int>;

const int N = 200005;

ppp ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i].first.second, &ary[i].first.first);
	}
	for (i=0; i<n; i++)
	{
		scanf(" %c", &ary[i].second);
	}
	sort(ary, ary+n);
	bool ans = false;
	for (i=1; i<n; i++)
	{
		if (ary[i].second == 'L')
		{
			if (ary[i-1].second == 'R' && ary[i-1].first.first == ary[i].first.first)
			{
				ans = true;
			}
		}
	}
	puts(ans ? "Yes" : "No");
	return 0;
}
