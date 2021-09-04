#include <iostream>

int a[128], b[128], tt[128];

int main()
{
	int count, n, i, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=1; i<=n; i++)
		{
			scanf("%d%d", &a[i], &b[i]);
		}
		for (i=1; i<=n; i++)
		{
			scanf("%d", &tt[i]);
		}
		for (i=1, t=0; i<=n; i++)
		{
			t += a[i]-b[i-1]+tt[i];
			if (i < n)
			{
				t += (b[i]-a[i]+1)/2;
				if (t < b[i])
				{
					t = b[i];
				}
			}
		}
		printf("%d\n", t);
	}
	return 0;
}
