#include <iostream>
#include <algorithm>
using namespace std;

int ary[1024], bry[1024];

int main()
{
	int n, m, i, j, k, t, mx, ans;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		for (i=0; i<m; i++)
		{
			cin >> bry[i];
		}
		for (k=0, ans=-2e9; k<2; k++)
		{
			for (i=0; i<n; i++)
			{
				for (j=0, t=0, mx=0; j<m&&j+i<n; j++)
				{
					t += bry[j]*ary[i+j];
					ans = max(ans, t-mx);
					mx = min(mx, t);
				}
			}
			for (i=0; i<m; i++)
			{
				for (j=0, t=0, mx=0; j<n&&j+i<m; j++)
				{
					t += ary[j]*bry[i+j];
					ans = max(ans, t-mx);
					mx = min(mx, t);
				}
			}
			reverse(ary, ary+n);
		}
		cout << ans << "\n";
	}
	return 0;
}

