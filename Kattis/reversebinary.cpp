#include <stdio.h>

int main()
{
	int n, ans;
	while (scanf("%d", &n) == 1)
	{
		for (ans=0; n; n>>=1)
		{
			ans = ((ans<<1) | (n&1));
		}
		printf("%d\n", ans);
	}
	return 0;
}
