#include <iostream>
using namespace std;

int main()
{
	int a, c, ans;
	long long b;
	scanf("%d%lld%d", &a, &b, &c);
	for (ans=1, a%=c; b; a=(a*a)%c, b>>=1)
	{
		if (b & 1)
		{
			ans = (ans * a) % c;
		}
	}
	printf("%d\n", ans);
	return 0;
}
