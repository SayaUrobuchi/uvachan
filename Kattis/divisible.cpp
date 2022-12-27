#include <iostream>
using namespace std;

int tbl[1048576];

int main()
{
	int count, n, m, i, cur, t;
	long long ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &m, &n);
		for (i=0; i<m; i++)
		{
			tbl[i] = 0;
		}
		tbl[0] = 1;
		for (i=0, cur=0, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			cur = (cur + t) % m;
			ans += tbl[cur]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}