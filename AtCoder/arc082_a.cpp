#include <iostream>
using namespace std;

int cnt[100050];

int main()
{
	int n, i, t, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		++t;
		++cnt[t];
	}
	for (i=1, ans=1; i<=100000; i++)
	{
		ans = max(ans, cnt[i-1]+cnt[i]+cnt[i+1]);
	}
	printf("%d\n", ans);
	return 0;
}