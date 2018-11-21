#include <stdio.h>

int main()
{
	int n, ans, f;
	while (scanf("%d", &n) == 1)
	{
		ans = 0;
		f = -1;
		while (n > 1)
		{
			ans += (n>>1);
			++f;
			n = ((n+1)>>1);
		}
		printf("%d\n", ans+f);
	}
	return 0;
}
