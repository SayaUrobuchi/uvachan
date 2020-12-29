#include <iostream>

int main()
{
	int n, m, p, q, r, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		n = ((n-4) >> 1);
		for (p=1, q=(n>>1); p<=q; )
		{
			r = ((p+q) >> 1);
			if (r * (n-r) <= m)
			{
				ans = r;
				p = r+1;
			}
			else
			{
				q = r-1;
			}
		}
		printf("%d %d\n", n-ans+2, ans+2);
	}
	return 0;
}
