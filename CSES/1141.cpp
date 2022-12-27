#include <iostream>
#include <set>
using namespace std;

int ary[262144];

int main()
{
	int n, i, j, ans;
	set<int> se;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		se.clear();
		for (i=0, j=0, ans=1; i<n; i++)
		{
			for (; j<n&&!se.count(ary[j]); se.insert(ary[j]), j++);
			ans = max(ans, j-i);
			se.erase(ary[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}

