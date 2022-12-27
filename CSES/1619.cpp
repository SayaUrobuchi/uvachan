#include <iostream>
#include <algorithm>
using namespace std;

int ary[262144], bry[262144];

int main()
{
	int n, i, j, t, ans;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i] >> bry[i];
		}
		sort(ary, ary+n);
		sort(bry, bry+n);
		for (i=0, j=0, t=0, ans=0; i<n; )
		{
			if (bry[j] <= ary[i])
			{
				--t;
				++j;
			}
			else
			{
				++t;
				++i;
			}
			ans = max(ans, t);
		}
		cout << ans << "\n";
	}
	return 0;
}

