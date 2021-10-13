#include <iostream>
using namespace std;

const int N = 1048576;

int h[N], dq[N], sc[N];

int main()
{
	int n, m, i, l, r, t, sum, ans, ant;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> h[i];
		}
		for (i=0, l=0, r=-1, sum=0, ans=-1e9; i<n; i++)
		{
			cin >> t;
			while (r >= l && h[dq[r]] <= h[i])
			{
				sum -= sc[r];
				--r;
			}
			while (l <= r && i-dq[l] >= m)
			{
				sum -= sc[l];
				++l;
			}
			++r;
			dq[r] = i;
			sc[r] = t;
			sum += t;
			if (sum > ans)
			{
				ans = sum;
				ant = i;
			}
		}
		cout << ant+1 << " " << ans << "\n";
	}
	return 0;
}
