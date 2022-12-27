#include <iostream>
#include <algorithm>
using namespace std;

const int N = 262144;

int ary[N], bry[N], ll[N], rr[N];

int main()
{
	int n, m, i, j, ans;
	while (cin >> m >> n)
	{
		ary[0] = 0;
		ary[n+1] = m;
		for (i=1; i<=n; i++)
		{
			cin >> ary[i];
			bry[i] = ary[i];
			ll[i] = i-1;
			rr[i] = i+1;
		}
		sort(ary+1, ary+n+1);
		for (i=1, ans=0; i<=n+1; i++)
		{
			ans = max(ans, ary[i]-ary[i-1]);
		}
		for (i=n; i>=1; i--)
		{
			j = lower_bound(ary+1, ary+n+1, bry[i]) - ary;
			bry[i] = ans;
			ans = max(ans, ary[rr[j]]-ary[ll[j]]);
			ll[rr[j]] = ll[j];
			rr[ll[j]] = rr[j];
		}
		cout << bry[1];
		for (i=2; i<=n; i++)
		{
			cout << " " << bry[i];
		}
		cout << "\n";
	}
	return 0;
}

