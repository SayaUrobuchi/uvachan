#include <iostream>
using namespace std;

int main()
{
	int n, m, o, i;
	scanf("%d%d%d", &n, &m, &o);
	long long ans = 0;
	for (i=0; i<n; i++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		ans += p * q;
	}
	if (ans < m)
	{
		ans += o;
	}
	printf("%lld\n", ans);
	return 0;
}
