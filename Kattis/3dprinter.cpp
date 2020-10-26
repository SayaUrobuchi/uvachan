#include <iostream>

int main()
{
	int n, i, t, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=1, ans=n; (1<<i)<=n; i++)
		{
			t = (n-1)/(1<<i)+1;
			if (i+t < ans)
			{
				ans = i+t;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
