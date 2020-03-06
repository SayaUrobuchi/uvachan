#include <iostream>
using namespace std;

int ary[32][32], sum[32];

int main()
{
	int n, i, j, k, t, ans, cur;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				cin >> ary[i][j];
			}
		}
		ans = 0;
		// from row i to row j
		for (i=0; i<n; i++)
		{
			for (k=0; k<n; k++)
			{
				sum[k] = 0;
			}
			for (j=i; j<n; j++)
			{
				for (k=0; k<n; k++)
				{
					sum[k] += ary[j][k];
				}
				t = 0;
				for (k=0, cur=0; k<n; k++)
				{
					cur += sum[k];
					if (cur < 0)
					{
						cur = 0;
					}
					if (cur > t)
					{
						t = cur;
					}
				}
				if (t > ans)
				{
					ans = t;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
