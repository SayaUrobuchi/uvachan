#include <stdio.h>

int main()
{
	int count, n, i, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=1, ans=0; n; n/=10, i*=10)
		{
			if (n%10)
			{
				ans += (n-1) * i;
				break;
			}
			ans += (n%10) * i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
