#include <iostream>
using namespace std;

int main()
{
	int n, m, i, t, best;
	scanf("%d%d", &n, &m);
	for (i=0, best=1e9; i<n; i++)
	{
		scanf("%d", &t);
		m -= t;
		best = min(best, t);
	}
	printf("%d\n", n+m/best);
	return 0;
}