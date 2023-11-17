#include <iostream>
using namespace std;
 
long long sum[200005];
 
int main()
{
	int n, m, i, t, a, b;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &t);
		sum[i] = (sum[i-1] ^ t);
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%lld\n", sum[b]^sum[a-1]);
	}
	return 0;
}
