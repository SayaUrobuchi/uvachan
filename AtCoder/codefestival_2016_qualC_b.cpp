#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	int best = -1;
	int sum = 0;
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		best = max(best, t);
		sum += t;
	}
	int ans = max(0, best - (sum - best + 1));
	printf("%d\n", ans);
	return 0;
}
