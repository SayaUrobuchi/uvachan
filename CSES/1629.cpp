#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> ary[262144];

int main()
{
	int n, i, last, ans;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i].first >> ary[i].second;
		}
		sort(ary, ary+n);
		for (i=0, ans=0, last=-1; i<n; i++)
		{
			if (ary[i].first >= last)
			{
				++ans;
				last = ary[i].second;
			}
			else
			{
				last = min(last, ary[i].second);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

