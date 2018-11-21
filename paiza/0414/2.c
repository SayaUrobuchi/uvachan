#include <stdio.h>
#include <string.h>

int ans[7];

int main()
{
	int n, i, t;
	while(scanf("%d", &n) == 1)
	{
		memset(ans, 0, sizeof(ans));
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			ans[i%7] += t;
		}
		for (i=0; i<7; i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}