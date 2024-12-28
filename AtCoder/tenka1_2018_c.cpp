#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;

int ary[N];

int main()
{
	int n, i, j, k, l;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	long long ans = 0;
	for (l=0; l<2; l++)
	{
		long long t = ary[n>>1] - ary[0];
		if (l)
		{
			t = ary[n-1] - ary[(n-1)>>1];
		}
		for (i=0, j=n-1, k=1; k<n-1; k++)
		{
			t += ary[j] - ary[i];
			if ((k & 1) != l)
			{
				++i;
			}
			else
			{
				--j;
			}
		}
		ans = max(ans, t);
	}
	printf("%lld\n", ans);
	return 0;
}