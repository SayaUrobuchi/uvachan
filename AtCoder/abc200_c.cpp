#include <iostream>
using namespace std;

int tbl[256];

int main()
{
	int n, i, t;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<200; i++)
		{
			tbl[i] = 0;
		}
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			t %= 200;
			ans += tbl[t];
			++tbl[t];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

