#include <iostream>
using namespace std;

int ary[262144];

int main()
{
	int n, i;
	long long cur, last, ans;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		for (i=0, ans=ary[0], last=0, cur=0; i<n; i++)
		{
			cur += ary[i];
			ans = max(ans, cur-last);
			last = min(last, cur);
		}
		cout << ans << "\n";
	}
	return 0;
}

