#include <stdio.h>
#include <string.h>

int a[1005];
char s[1005][25];

int main()
{
	int cas, count, n, m, i;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s%d", s[i], &a[i]);
		}
		scanf("%d%s", &m, s[n]);
		for(i=0; i<n; i++)
		{
			if(strcmp(s[n], s[i]) == 0)
			{
				break;
			}
		}
		if(i >= n || a[i] > m+5)
		{
			printf("Case %d: Do your own homework!\n", ++cas);
		}
		else if(a[i] > m)
		{
			printf("Case %d: Late\n", ++cas);
		}
		else
		{
			printf("Case %d: Yesss\n", ++cas);
		}
	}
	return 0;
}
