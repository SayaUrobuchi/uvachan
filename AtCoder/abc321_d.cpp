#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;

int ary[N], bry[N];
long long sum[N];

int main()
{
	int n, m, o, i, j;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1; i<=m; i++)
	{
		scanf("%d", &bry[i]);
	}
	sort(ary, ary+n);
	sort(bry+1, bry+m+1);
	for (i=1; i<=m; i++)
	{
		sum[i] = sum[i-1] + bry[i];
	}
	long long ans = 0;
	for (i=0, j=m; i<n; i++)
	{
		for (; j>0&&bry[j]+ary[i]>=o; j--);
		ans += ary[i]*1LL*j + sum[j];
		ans += o*1LL*(m-j);
	}
	printf("%lld\n", ans);
	return 0;
}
