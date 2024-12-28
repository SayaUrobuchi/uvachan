/*
	ID: sa072682
	LANG: C
	TASK: prefix
*/
#include <stdio.h>
#include <string.h>

char s[201][11], str[200001], tbl[200001];

int main()
{
	int n, m, i, j, k, ans;
	char buf[101];
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	m = 0;
	while(scanf("%s", s[m]) == 1)
	{
		if(s[m][0] == '.')
		{
			break;
		}
		m++;
	}
	str[0] = 0;
	while(scanf("%s", buf) == 1)
	{
		strcat(str, buf);
	}
	n = strlen(str);
	tbl[0] = 1;
	for(i=0, ans=0; i<n; i++)
	{
		if(tbl[i])
		{
			if(i)
			{
				ans = i;
			}
			for(j=0; j<m; j++)
			{
				for(k=0; s[j][k]&&str[i+k]; k++)
				{
					if(s[j][k] != str[i+k])
					{
						break;
					}
				}
				if(!s[j][k])
				{
					tbl[i+k] = 1;
				}
			}
		}
	}
	if(i && tbl[i])
	{
		ans = i;
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}
