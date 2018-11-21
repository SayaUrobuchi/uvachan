#include <stdio.h>

int main()
{
	int p, q, t, ans;
	while (scanf("%d%d", &p, &q) == 2)
	{
		if (!p && !q)
		{
			break;
		}
		t = 0;
		ans = 0;
		while (p || q)
		{
			t = (p%10+q%10+t) / 10;
			ans += t;
		}
		if (!ans)
		{
			puts("No carry operation.");
		}
		else
		{
			printf(ans==1 ? "%d carry operation.\n" : "%d carry operations.\n", ans);
		}
	}
	return 0;
}
