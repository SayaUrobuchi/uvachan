#include <iostream>
using namespace std;

const int M = 86405;

int pre[M];

int main()
{
	int n, m, i, j, a, b, best, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &m);
		for (j=0; j<m; j++)
		{
			scanf("%d%d", &a, &b);
			++pre[a];
			--pre[b+1];
		}
	}
	for (i=1, best=pre[0]; i<M; i++)
	{
		pre[i] += pre[i-1];
		best = max(best, pre[i]);
	}
	for (i=0, ans=0; i<M; i++)
	{
		ans += (pre[i] == best);
	}
	printf("%d\n%d\n", best, ans);
	return 0;
}
