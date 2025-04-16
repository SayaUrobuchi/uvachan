#include <iostream>
using namespace std;

int ary[105];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		ary[i] += ary[i-1];
	}
	int ans = ary[n];
	for (i=1; i<=n; i++)
	{
		int l = ary[i];
		int r = ary[n] - ary[i];
		ans = min(ans, abs(l-r));
	}
	printf("%d\n", ans);
	return 0;
}
