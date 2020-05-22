#include <stdio.h>

int ucnt;
int ary[1048576];

int main()
{
	int n, i, j, p, q, ans;
	while (scanf("%d", &n) == 1)
	{
		ucnt++;
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			for (j=p; j<=q; j++)
			{
				if (ary[j] != ucnt)
				{
					ary[j] = ucnt;
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
