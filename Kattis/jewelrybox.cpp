#include <stdio.h>
#include <algorithm>

int main()
{
	int count, a, b;
	double p, q, t, u, c, d, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &a, &b);
		if (a > b)
		{
			std::swap(a, b);
		}
		for (p=0, q=a/2.0, ans=0; q-p>1e-8; )
		{
			t = p + (q-p)/3;
			u = q - (q-p)/3;
			c = t * (a-t-t) * (b-t-t);
			d = u * (a-u-u) * (b-u-u);
			if (c > d)
			{
				q = u;
				ans = c;
			}
			else
			{
				p = t;
				ans = d;
			}
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
