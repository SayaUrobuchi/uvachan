#include <iostream>
using namespace std;

const int N = 300005;

int ary[N], pre[N];

int main()
{
	int n, i, l, r, ll, rr;
	scanf("%d", &n);
	l = r = 0;
	ll = rr = 0;
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		if (ary[i])
		{
			pre[i] = pre[i-1] + 1;
		}
		else
		{
			pre[i] = pre[i-1] - 1;
		}
		ll = min(ll, pre[i]-r);
		rr = max(rr, pre[i]-l);
		l = min(l, pre[i]);
		r = max(r, pre[i]);
	}
	printf("%d\n", rr-ll+1);
	return 0;
}
