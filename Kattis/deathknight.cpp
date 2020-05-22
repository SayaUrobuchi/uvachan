#include <stdio.h>

char s[1048576];

int main()
{
	int n, i, j, last, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%s", s);
			for (j=0, last=0; s[j]; last=s[j], j++)
			{
				if (s[j] == 'D' && last == 'C')
				{
					break;
				}
			}
			if (!s[j])
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
