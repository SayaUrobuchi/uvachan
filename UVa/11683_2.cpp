#include <iostream>
using namespace std;

int main()
{
	int n, m, i, t, last, ans;
	while (scanf("%d%d", &m, &n) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i=0, last=1e9, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			if (t > last)
			{
				ans += t - last;
			}
			last = t;
		}
		ans += m - last;
		printf("%d\n", ans);
	}
	return 0;
}
