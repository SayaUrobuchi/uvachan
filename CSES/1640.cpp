#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> ary[262144];

int main()
{
	int n, m, i, j;
	bool gg;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i].first;
			ary[i].second = i+1;
		}
		sort(ary, ary+n);
		for (i=0, j=n-1, gg=true; i<j; i++)
		{
			for (; j>i&&ary[i].first+ary[j].first>m; j--);
			if (j > i && ary[i].first+ary[j].first == m)
			{
				gg = false;
				break;
			}
		}
		if (gg)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			cout << ary[i].second << " " << ary[j].second << "\n";
		}
	}
	return 0;
}

