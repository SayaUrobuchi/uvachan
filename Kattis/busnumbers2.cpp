#include <iostream>

int ary[1048576];

int main()
{
	int n, m, i, a, b, t, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i*i*i<=n; i++)
		{
			ary[i] = i*i*i;
		}
		m = i;
		ans = -1;
		for (i=n; i>0; i--)
		{
			for (a=1, b=m-1, t=0; a<=b; a++)
			{
				for (; b>=a&&ary[a]+ary[b]>i; b--);
				if (b >= a && ary[a]+ary[b] == i)
				{
					++t;
				}
			}
			if (t >= 2)
			{
				ans = i;
				break;
			}
		}
		if (ans < 0)
		{
			puts("none");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}
