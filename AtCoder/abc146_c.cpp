#include <iostream>

int main()
{
	int a, b, i;
	long long c, j, ans;
	while (scanf("%d%d%lld", &a, &b, &c) == 3)
	{
		for (i=1, j=9, c-=b, ans=0; i<=10&&c>0; i++, j=j*10+9, c-=b)
		{
			if (c/a >= j)
			{
				ans = j;
			}
			else if (c/a > ans)
			{
				ans = c/a;
			}
		}
		if (ans > 1e9)
		{
			ans = 1e9;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
