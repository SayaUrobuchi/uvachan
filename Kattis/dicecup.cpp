#include <stdio.h>
#include <string.h>

int ary[1024];

int main()
{
	int n, m, i, j, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(ary, 0, sizeof(ary));
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=m; j++)
			{
				ary[i+j]++;
			}
		}
		for (i=1, ans=0; i<=n*m; i++)
		{
			if (ary[i] > ans)
			{
				ans = ary[i];
			}
		}
		for (i=1; i<=n*m; i++)
		{
			if (ary[i] == ans)
			{
				printf("%d\n", i);
			}
		}
	}
	return 0;
}
