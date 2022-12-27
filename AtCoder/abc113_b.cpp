#include <iostream>
using namespace std;

int main()
{
	int n, m, i, o, t, d, best, ans;
	scanf("%d%d%d", &n, &m, &o);
	m *= 1000;
	o *= 1000;
	for (i=1, best=2000000; i<=n; i++)
	{
		scanf("%d", &t);
		d = m - t * 6;
		if (abs(d-o) < best)
		{
			best = abs(d-o);
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}