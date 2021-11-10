#include <iostream>
using namespace std;

int ary[4], tbl[128];
char buf[1048576];

int main()
{
	int n, i, t, u;
	long long ans;
	tbl['o'] = 0;
	tbl['x'] = 1;
	while (scanf("%d", &n) == 1)
	{
		scanf("%s", buf);
		ary[0] = ary[1] = -1;
		for (i=0, ans=0; i<n; i++)
		{
			t = tbl[buf[i]];
			u = (t^1);
			ary[t] = i;
			ans += ary[u]+1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
