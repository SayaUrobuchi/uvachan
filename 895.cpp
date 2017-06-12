#include <stdio.h>
#include <string.h>

char dic[1000][11], table[27], tmp[27];

int main()
{
	char chr, buf[1001];
	int n, i, j, ans;
	n = 0;
	while(gets(dic[n]))
	{
		if(dic[n][0] == '#')
		{
			break;
		}
		for(i=0; dic[n][i]; i++)
		{
			dic[n][i] -= 96;
		}
		n++;
	}
	while(gets(buf))
	{
		if(buf[0] == '#')
		{
			break;
		}
		memset(table, 0, sizeof(table));
		for(i=0; buf[i]; i++)
		{
			if(buf[i] > 96 && buf[i] < 123)
			{
				table[buf[i]-96]++;
			}
		}
		ans = 0;
		for(i=0; i<n; i++)
		{
			memset(tmp, 0, sizeof(tmp));
			for(j=0; dic[i][j]; j++)
			{
				tmp[dic[i][j]]++;
				if(table[dic[i][j]] < tmp[dic[i][j]])
				{
					break;
				}
			}
			if(!dic[i][j])
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
