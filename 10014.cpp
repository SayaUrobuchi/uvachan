#include <stdio.h>

int n, temp;

int main()
{
	int count, i;
	double c, a0, an, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%lf%lf", &n, &a0, &an);
		ans = a0 * n + an;
		for(i=1, temp=n+n; i<=n; i++, temp-=2)
		{
			scanf("%lf", &c);
			ans -= c * temp;
		}
		printf("%.2f\n", ans/(n+1));
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
