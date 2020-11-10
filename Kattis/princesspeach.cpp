#include <iostream>

int ucnt;
int used[128];

int main()
{
	int n, m, i, ans, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		++ucnt;
		for (i=0, ans=0; i<m; i++)
		{
			scanf("%d", &t);
			if (used[t] != ucnt)
			{
				used[t] = ucnt;
				++ans;
			}
		}
		for (i=0; i<n; i++)
		{
			if (used[i] != ucnt)
			{
				printf("%d\n", i);
			}
		}
		printf("Mario got %d of the dangerous obstacles.\n", ans);
	}
	return 0;
}
