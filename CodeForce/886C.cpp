#include <stdio.h>

int ucnt;
int used[1048576];

int main()
{
	int n, i, t, ans;
	while (scanf("%d", &n) == 1)
	{
		ucnt++;
		for (i=0, ans=1; i<n; i++)
		{
			scanf("%d", &t);
			if (used[t] != ucnt)
			{
				used[t] = ucnt;
			}
			else
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
