#include <stdio.h>

int ary[1048576];

int main()
{
	int n, i, j, p, q;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0, j=n-1, ans=0; i<j; )
		{
			p = ary[i] * ary[i+1];
			q = ary[j] * ary[j-1];
			if (p > q || (p == q && ary[i] > ary[j]))
			{
				ans += p;
				i++;
			}
			else
			{
				ans += q;
				j--;
			}
		}
		printf("%lld\n", ans+ary[i]);
	}
	return 0;
}
