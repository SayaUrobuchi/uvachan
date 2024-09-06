#include <iostream>
using namespace std;

const int N = 100005;

int cur[N], add[N];

int main()
{
    int n, m, i;
    scanf("%d%d", &m, &n);
    int mx = 0;
    for (i=0; i<n; i++)
    {
        scanf("%d%d", &cur[i], &add[i]);
        mx = max(mx, cur[i]);
    }
    long long l, r, ans;
    for (l=mx, r=1e15; l<=r; )
    {
    	long long mid = ((l + r) >> 1);
    	long long t = 0;
    	for (i=0; i<n; i++)
    	{
    		t += (mid - cur[i]) / add[i];
    	}
    	if (t >= m)
    	{
    		ans = mid;
    		r = mid - 1;
    	}
    	else
    	{
    		l = mid + 1;
    	}
    }
    printf("%lld\n", ans);
    return 0;
}