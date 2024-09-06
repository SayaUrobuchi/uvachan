#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;

int ary[N], bry[N];

int main()
{
	int n, m, i, l, r, a, b, ans;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0; i<m; i++)
	{
		scanf("%d", &bry[i]);
	}
	sort(ary, ary+n);
	sort(bry, bry+m);
	for (l=0, r=1e9+5; l<=r; )
	{
		int mid = ((l + r) >> 1);
		a = upper_bound(ary, ary+n, mid) - ary;
		b = lower_bound(bry, bry+m, mid) - bry;
		b = m - b;
		if (a >= b)
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
