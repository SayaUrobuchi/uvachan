#include <stdio.h>
#include <string.h>

char s[128][128];

int main()
{
	int count, n, i, j, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%s", s[i]);
			for (j=0; j<i; j++)
			{
				if (strcmp(s[i], s[j]) == 0)
				{
					break;
				}
			}
			if (j >= i)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
