#include <iostream>
#include <algorithm>
using namespace std;

int ary[1024], bry[1024];

int main()
{
	int n, m, i, j, k, t, pos, mx, ans;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		for (i=0, ans=-2e9; i<m; i++)
		{
			cin >> bry[i];
			for (j=0; j<n; j++)
			{
				ans = max(ans, ary[j]*bry[i]);
			}
		}
		for (k=0; k<2; k++)
		{
			for (i=0; i<n; i++)
			{
				for (j=1, mx=t=bry[0]*ary[i], pos=0; j<m&&j+i<n; j++)
				{
					t += bry[j]*ary[i+j];
					if (t >= mx)
					{
						mx = t;
						pos = j;
					}
				}
				for (j=0; j<=pos; j++)
				{
					ans = max(ans, mx);
					mx -= bry[j]*ary[i+j];
				}
			}
			for (i=0; i<m; i++)
			{
				for (j=1, mx=t=ary[0]*bry[i], pos=0; j<n&&j+i<m; j++)
				{
					t += ary[j]*bry[i+j];
					if (t >= mx)
					{
						mx = t;
						pos = j;
					}
				}
				for (j=0; j<=pos; j++)
				{
					ans = max(ans, mx);
					mx -= ary[j]*bry[i+j];
				}
			}
			reverse(ary, ary+n);
		}
		cout << ans << "\n";
	}
	return 0;
}

