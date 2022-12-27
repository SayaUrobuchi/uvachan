#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1048576;

int ary[N];
long long h[N], g[N], ans[N];

int main()
{
	int n, i, j, v, t;
	long long sum;
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			cin >> ary[i];
			ans[i] = 0;
		}
		h[0] = 2e9;
		for (j=0; j<2; j++)
		{
			for (i=0, t=0; i<n; i++)
			{
				for (sum=0; ary[i]>h[t]; sum+=g[t]+h[t], --t);
				++t;
				h[t] = ary[i];
				g[t] = sum;
				ans[i] += sum;
			}
			reverse(ary, ary+n);
			reverse(ans, ans+n);
		}
		for (i=0; i<n; i++)
		{
			cout << ans[i] << "\n";
		}
	}
	return 0;
}
