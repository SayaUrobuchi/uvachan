#include <stdio.h>

int ary[1000005];

int main()
{
	int n, m, i, j, a, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		ans = 0;
		for(i=0, j=0; i<m; i++)
		{
			scanf("%d", &a);
			for(; j<n&&ary[j]<a; j++);
			if(j >= n)
			{
				for(i++; i<m; i++)
				{
					scanf("%d", &a);
				}
				break;
			}
			if(ary[j] == a)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
