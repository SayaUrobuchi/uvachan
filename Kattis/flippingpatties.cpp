#include <iostream>
#include <cstring>

int tbl[65536];

int main()
{
	int n, i, ans, a, b;
	while (scanf("%d", &n) == 1)
	{
		memset(tbl, 0, sizeof(tbl));
		for (i=0, ans=1; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			++tbl[b];
			++tbl[b-a];
			++tbl[b-(a<<1)];
			ans = std::max(ans, std::max(tbl[b], std::max(tbl[b-a], tbl[b-(a<<1)])));
		}
		printf("%d\n", (ans+1)>>1);
	}
	return 0;
}
