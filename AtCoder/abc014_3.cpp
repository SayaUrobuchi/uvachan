#include <iostream>
using namespace std;

int diff[1048576];

int main()
{
	int n, i, a, b, cur, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &a, &b);
		++diff[a];
		--diff[b+1];
	}
	for (i=0, cur=0, ans=0; i<=1000000; i++)
	{
		ans = max(ans, cur += diff[i]);
	}
	printf("%d\n", ans);
	return 0;
}