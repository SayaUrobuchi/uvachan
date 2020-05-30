#include <stdio.h>

int ucnt, used[16];

int main()
{
	int count, n, i, j, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		ucnt += 16;
		for (i=-1, t=1; t<=n; t++)
		{
			for (j=0; j<=t; )
			{
				i = (i+1)%n;
				if (used[i] < ucnt)
				{
					j++;
				}
			}
			used[i] = ucnt + t;
		}
		printf("%d", used[0]&15);
		for (i=1; i<n; i++)
		{
			printf(" %d", used[i]&15);
		}
		puts("");
	}
	return 0;
}
