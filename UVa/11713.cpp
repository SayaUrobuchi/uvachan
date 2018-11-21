#include <stdio.h>
#include <string.h>

int tbl[128];
char s1[100005], s2[100005];

int main()
{
	int n, i;
	tbl['a'] = tbl['e'] = tbl['i'] = tbl['o'] = tbl['u'] = 1;
	while(scanf("%d", &n) == 1)
	{
		while(n--)
		{
			scanf("%s%s", s1, s2);
			if(strlen(s1) != strlen(s2))
			{
				printf("No\n");
				continue;
			}
			for(i=0; s1[i]; i++)
			{
				if(tbl[s1[i]] != tbl[s2[i]])
				{
					break;
				}
				if(tbl[s1[i]] == 0 && s1[i] != s2[i])
				{
					break;
				}
			}
			if(s1[i])
			{
				printf("No\n");
			}
			else
			{
				printf("Yes\n");
			}
		}
	}
	return 0;
}
