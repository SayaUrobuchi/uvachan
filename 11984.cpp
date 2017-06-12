#include <stdio.h>

int main()
{
	int cas, count, c, d;
	double ans;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &c, &d);
		ans = c + d*5/9.0;
		printf("Case %d: %.2lf\n", ++cas, ans);
	}
	return 0;
}
