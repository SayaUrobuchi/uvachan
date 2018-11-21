#include <stdio.h>
#include <string.h>

int tbl[26];
char str[100010];

int main()
{
	int count, n, i, maxnum;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%s", &n, str);
		memset(tbl, 0, sizeof(tbl));
		for(i=0; i<n; i++)
		{
			tbl[str[i]-97]++;
		}
		for(i=0, maxnum=0; i<26; i++)
		{
			if(tbl[i] > maxnum)
			{
				maxnum = tbl[i];
			}
		}
		for(i=0; i<26; i++)
		{
			if(tbl[i] == maxnum)
			{
				printf("%c", i+97);
			}
		}
		printf("\n");
	}
	return 0;
}
