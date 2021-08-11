#include <iostream>
#include <algorithm>
using namespace std;

int ary[1048576];

int main()
{
	int n, m, i, j, t;
	long long ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			ary[i] /= m;
		}
		sort(ary, ary+n);
		for (i=0, ans=0; i<n; i=j)
		{
			for (j=i+1; j<n&&ary[i]==ary[j]; j++);
			t = j-i;
			ans += (long long)t*(t-1)/2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
