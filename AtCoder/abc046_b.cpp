#include <iostream>
using namespace std;

int main()
{
	int n, k, t, ans;
	scanf("%d%d", &n, &k);
	for (--n, t=k-1, ans=k; n; n>>=1, t*=t)
	{
		if (n & 1)
		{
			ans *= t;
		}
	}
	printf("%d\n", ans);
	return 0;
}
