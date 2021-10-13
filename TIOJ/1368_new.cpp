#include <iostream>
using namespace std;

const int N = 131072;

int ary[N], pos[N];
long long sum[N];

int main()
{
	int n, i, t, sn, a, b;
	long long ans, u;
	while (cin >> n)
	{
		for (i=1, sn=0, ans=0, a=0, b=0; i<=n+1; i++)
		{
			if (i <= n)
			{
				cin >> t;
			}
			else
			{
				t = 0;
			}
			ary[i] = t;
			sum[i] = sum[i-1] + t;
			while (sn > 0 && ary[pos[sn]] >= t)
			{
				u = ary[pos[sn]] * (sum[i-1]-sum[pos[sn-1]]);
				if (u > ans || (u == ans && pos[sn-1]+1 < a))
				{
					ans = u;
					a = pos[sn-1] + 1;
					b = i-1;
				}
				--sn;
			}
			++sn;
			pos[sn] = i;
		}
		cout << ans << "\n";
		cout << a << " " << b << "\n";
	}
	return 0;
}
