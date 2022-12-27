#include <iostream>
using namespace std;

int main()
{
	int n, i, t, last;
	long long ans;
	while (cin >> n)
	{
		for (i=0, ans=0, last=-2e9; i<n; i++)
		{
			cin >> t;
			if (t > last)
			{
				last = t;
			}
			else
			{
				ans += last - t;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

