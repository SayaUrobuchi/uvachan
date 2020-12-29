#include <iostream>

int ary[1048576];

int main()
{
	int count, n, m, i, t, ans;
	long long a, b;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=0, a=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			a += ary[i];
		}
		for (i=0, b=0; i<m; i++)
		{
			scanf("%d", &t);
			b += t;
		}
		for (i=0, ans=0; i<n; i++)
		{
			if ((long long)ary[i]*n < a && (long long)ary[i]*m > b)
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
