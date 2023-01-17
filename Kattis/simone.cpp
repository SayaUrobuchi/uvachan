#include <iostream>
using namespace std;

const int N = 1005;
const int M = 1005;

int ary[N], cnt[M];

int main()
{
	int n, m, i, t, best, bn;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		cnt[t]++;
	}
	for (i=2, best=cnt[1]; i<=m; i++)
	{
		best = min(best, cnt[i]);
	}
	for (i=1, bn=0; i<=m; i++)
	{
		if (cnt[i] == best)
		{
			ary[bn] = i;
			++bn;
		}
	}
	printf("%d\n", bn);
	for (i=0; i<bn; i++)
	{
		if (i)
		{
			printf(" ");
		}
		printf("%d", ary[i]);
	}
	puts("");
	return 0;
}
