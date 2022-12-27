#include <iostream>
using namespace std;

long long ary[131072];

int main()
{
	int n, m, i, l, r, mid, ans;
	long long t;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n >> m)
	{
		for (i=1; i<=n; i++)
		{
			cin >> ary[i];
		}
		for (i=0; i<m; i++)
		{
			cin >> t;
			for (l=0, r=n; l<=r; )
			{
				mid = ((l+r) >> 1);
				if (ary[mid] - mid < t)
				{
					l = mid + 1;
					ans = mid;
				}
				else
				{
					r = mid - 1;
				}
			}
			cout << ary[ans]+(t-(ary[ans]-ans)) << "\n";
		}
	}
	return 0;
}
