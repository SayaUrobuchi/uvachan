#include <iostream>
using namespace std;

const int N = 100005;
const int M = 100005;

int px[N], py[N];
int xx[M], yy[M];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &px[i], &py[i]);
		++xx[px[i]];
		++yy[py[i]];
	}
	long long ans = 0;
	for (i=0; i<n; i++)
	{
		ans += (xx[px[i]]-1) * 1LL * (yy[py[i]]-1);
	}
	printf("%lld\n", ans);
	return 0;
}