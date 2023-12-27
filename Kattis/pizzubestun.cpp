#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int n, i;
	long long ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%*s%d", &ary[i]);
	}
	if (n & 1)
	{
		ary[n++] = 0;
	}
	sort(ary, ary+n);
	for (i=1, ans=0; i<n; i+=2)
	{
		ans += ary[i];
	}
	printf("%lld\n", ans);
	return 0;
}
