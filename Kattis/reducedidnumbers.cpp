#include <iostream>

int ucnt, used[1048576];
int ary[512];

int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=1; i<=999999; i++)
		{
			for (j=0, ++ucnt; j<n; j++)
			{
				if (used[ary[j]%i] == ucnt)
				{
					break;
				}
				used[ary[j]%i] = ucnt;
			}
			if (j >= n)
			{
				break;
			}
		}
		printf("%d\n", i);
	}
	return 0;
}
