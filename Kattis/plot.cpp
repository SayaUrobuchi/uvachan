#include <iostream>

int ary[1024], ans[1024];

int main()
{
	int n, i, j, r, t, last, p, q, u;
	while (scanf("%d", &n) == 1)
	{
		for (i=n; i>=0; i--)
		{
			scanf("%d", &ary[i]);
		}
		printf("%d", ary[0]);
		last = ary[0];
		for (i=1; i<=n; i++)
		{
			for (r=ary[0], t=1, j=1; j<=n; r+=(t*=i)*ary[j++]);
			for (t=0, p=i-1, q=1, u=1, j=1; j<i; t+=ans[j++]*u, u=u*p--/q++);
			ans[i] = (r-last) - t;
			printf(" %d", ans[i]);
			last = r;
		}
		puts("");
	}
	return 0;
}
