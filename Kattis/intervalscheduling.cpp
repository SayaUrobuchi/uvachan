#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

pair<int, int> ary[N];

int main()
{
	int n, i, last, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i].first, &ary[i].second);
	}
	sort(ary, ary+n);
	for (i=0, last=-1, ans=0; i<n; i++)
	{
		if (ary[i].first >= last)
		{
			last = ary[i].second;
			++ans;
		}
		else if (ary[i].second < last)
		{
			last = ary[i].second;
		}
	}
	printf("%d\n", ans);
	return 0;
}
