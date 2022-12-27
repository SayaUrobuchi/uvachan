#include <iostream>
using namespace std;

int main()
{
	int n, l, r, mid, ans;
	while (cin >> n)
	{
		for (l=1, r=80000; l<=r; )
		{
			mid = ((l+r) >> 1);
			if ((mid+1)*(long long)mid/2 >= n)
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
