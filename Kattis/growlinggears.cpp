#include <iostream>

int main()
{
	int count, n, i, a, b, c, ans;
	double x, t, best;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, best=-1e15; i<n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			x = b/(2.0*a);
			t = -a*x*x + b*x + c;
			if (t > best)
			{
				best = t;
				ans = i;
			}
		}
		printf("%d\n", ans+1);
	}
	return 0;
}
