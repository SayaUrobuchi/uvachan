#include <iostream>
using namespace std;

int n;
int ary[262144], bry[262144];

int main()
{
	int m, i, t, last, ans, a, b, u;
	bool as, ab, bs, bb;
	while (cin >> n >> m)
	{
		for (i=0; i<n; i++)
		{
			cin >> bry[i];
			ary[bry[i]] = i;
		}
		for (i=1, ans=1, last=-1; i<=n; i++)
		{
			if (ary[i] < last)
			{
				++ans;
			}
			last = ary[i];
		}
		for (i=0; i<m; i++)
		{
			cin >> a >> b;
			swap(bry[--a], bry[--b]);
			a = bry[a];
			b = bry[b];
			as = (a > 1 && ary[a] < ary[a-1]);
			ab = (a+1 <= n && ary[a] < ary[a+1]);
			bs = (b > 1 && ary[b] < ary[b-1]);
			bb = (b+1 <= n && ary[b] < ary[b+1]);
			swap(ary[a], ary[b]);
			if (a > 1 && ary[a] < ary[a-1] && !as)
			{
				++ans;
			}
			if (a > 1 && ary[a] > ary[a-1] && as)
			{
				--ans;
			}
			if (a+1 <= n && ary[a] < ary[a+1] && !ab)
			{
				--ans;
			}
			if (a+1 <= n && ary[a] > ary[a+1] && ab)
			{
				++ans;
			}
			//printf(".... %d (%d)\n", ans, a);
			if (b-1 != a && b > 1 && ary[b] < ary[b-1] && !bs)
			{
				++ans;
			}
			if (b-1 != a && b > 1 && ary[b] > ary[b-1] && bs)
			{
				--ans;
			}
			if (b+1 != a && b+1 <= n && ary[b] < ary[b+1] && !bb)
			{
				--ans;
			}
			if (b+1 != a && b+1 <= n && ary[b] > ary[b+1] && bb)
			{
				++ans;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}

