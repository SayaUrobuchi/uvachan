#include <iostream>

int main()
{
	int n, i, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=2, ans=0; i*i<=n; i++)
		{
			while (n%i == 0)
			{
				++ans;
				n /= i;
			}
		}
		if (n > 1)
		{
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
