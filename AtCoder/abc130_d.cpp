#include <iostream>
using namespace std;

int ary[100005];

int main()
{
	int n, i, j;
	long long m, t, ans;
	scanf("%d%lld", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0, j=0, t=0, ans=0; i<n; i++)
	{
		for (; j<n&&t+ary[j]<m; t+=ary[j], j++);
		ans += n-j;
		t -= ary[i];
	}
	printf("%lld\n", ans);
	return 0;
}