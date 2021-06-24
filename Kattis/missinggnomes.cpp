#include <iostream>

int ucnt, used[131072];
int ary[131072];

int main()
{
	int n, m, i, j;
	while (scanf("%d%d", &n, &m) == 2)
	{
		++ucnt;
		for (i=0; i<m; i++)
		{
			scanf("%d", &ary[i]);
			used[ary[i]] = ucnt;
		}
		ary[m] = 1e9;
		for (i=1, j=0; i<=n; )
		{
			if (used[i] == ucnt)
			{
				++i;
				continue;
			}
			if (i < ary[j])
			{
				printf("%d\n", i);
				++i;
			}
			else
			{
				printf("%d\n", ary[j]);
				++j;
			}
		}
		for (; j<m; j++)
		{
			printf("%d\n", ary[j]);
		}
	}
	return 0;
}
