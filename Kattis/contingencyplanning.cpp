#include <iostream>
using namespace std;

int main()
{
	int n, i, p, q;
	long long t, r, ans;
	scanf("%d", &n);
	for (i=1, t=n, p=n-1, q=2, r=1, ans=0; i<=n&&ans<=1e9; i++, p--, q++)
	{
		r *= i;
		ans += t * r;
		t *= p;
		t /= q;
	}
	if (ans > 1e9)
	{
		puts("JUST RUN!!");
	}
	else
	{
		printf("%lld\n", ans);
	}
	return 0;
}
