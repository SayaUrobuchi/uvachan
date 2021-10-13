#include <iostream>
#include <algorithm>
using namespace std;

int bry[1048576];
long long sum[1048576];
pair<int, int> ary[1048576];

int main()
{
	int n, i, l, r, t;
	long long a, b;
	while (cin >> n)
	{
		for (i=1; i<=n; i++)
		{
			cin >> t;
			bry[i] = t;
			sum[i] = sum[i-1] + t;
			ary[i-1] = {t, i};
		}
		sort(ary, ary+n);
		for (i=0, l=1, r=n; i<n&&l!=r; i++)
		{
			if (ary[i].second >= l && ary[i].second <= r)
			{
				a = 0;
				b = 0;
				if (ary[i].second > l)
				{
					a = sum[ary[i].second-1] - sum[l-1];
				}
				if (ary[i].second < r)
				{
					b = sum[r] - sum[ary[i].second];
				}
				if (a > b)
				{
					r = ary[i].second-1;
				}
				else
				{
					l = ary[i].second+1;
				}
			}
		}
		cout << bry[l] << "\n";
	}
	return 0;
}
