#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144];

int main()
{
	int n, i, t;
	long long ans;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		sort(ary, ary+n);
		t = ary[n>>1];
		for (i=0, ans=0; i<n; i++)
		{
			ans += abs(ary[i]-t);
		}
		cout << ans << "\n";
	}
	return 0;
}

