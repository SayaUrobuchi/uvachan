#include <stdio.h>

int ary[100005];

int main()
{
	int n, m, i, sum, st, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, sum=0, st=0, ans=n+1; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
			while (sum >= m && st <= i)
			{
				if (i-st+1 < ans)
				{
					ans = i-st+1;
				}
				sum -= ary[st];
				st++;
			}
		}
		if (ans > n)
		{
			ans = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
