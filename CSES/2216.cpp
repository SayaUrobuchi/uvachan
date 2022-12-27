#include <iostream>
using namespace std;

int ary[262144];

int main()
{
	int n, i, t, last, ans;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> t;
			ary[t] = i;
		}
		for (i=1, ans=1, last=-1; i<=n; i++)
		{
			if (ary[i] < last)
			{
				++ans;
			}
			last = ary[i];
		}
		cout << ans << "\n";
	}
	return 0;
}

