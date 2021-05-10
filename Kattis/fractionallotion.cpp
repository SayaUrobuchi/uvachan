#include <iostream>

int main()
{
	int n, i, ans;
	while (scanf(" 1/%d", &n) == 1)
	{
		for (i=n+1, ans=1; i<n+n; i++)
		{
			if ((n*i) % (i-n) == 0)
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
