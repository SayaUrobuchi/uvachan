#include <iostream>
using namespace std;

int ary[200005];

int main()
{
	int n, i, j, t;
	long long ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0, j=0, t=0, ans=0; i<n; i++)
	{
		for (; j<n&&(t^ary[j])==(t+ary[j]); t^=ary[j], j++);
		ans += j-i;
		t ^= ary[i];
	}
	printf("%lld\n", ans);
	return 0;
}