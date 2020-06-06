#include <stdio.h>

int main()
{
	int cas, n, m, ans;
	cas = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		ans = 0;
		if (n)
		{
			ans = 365-n;
			m += 365-n;
			m %= 687;
			n = 0;
		}
		while (m)
		{
			m = (m+365) % 687;
			ans += 365;
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
