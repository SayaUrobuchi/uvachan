#include <stdio.h>
#include <string.h>

char str[100][81];

int main()
{
	int count, i, j, n;
	char compare[44], buf[81], isfind, isans, table[127], check[127];
	strcpy(compare, "the quick brown fox jumps over the lazy dog");
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		isfind = 1;
		isans = 0;
		n = 0;
		while(gets(buf))
		{
			if(!buf[0]) break;
			if(isfind && strlen(buf) == 43)
			{
				memset(table, 0, sizeof(table));
				memset(check, 0, sizeof(check));
				for(i=0; buf[i]; i++)
				{
					if(compare[i] == 32)
					{
						if(compare[i] != buf[i])
						{
							break;
						}
					}
					else
					{
						if(check[compare[i]] && check[compare[i]] != buf[i] || table[buf[i]] && table[buf[i]] != compare[i])
						{
							break;
						}
						table[buf[i]] = compare[i];
						check[compare[i]] = buf[i];
					}
				}
				if(!buf[i])
				{
					isfind = 0;
					isans = 1;
				}
			}
			strcpy(str[n++], buf);
		}
		if(isans)
		{
			for(i=0; i<n; i++)
			{
				for(j=0; str[i][j]; j++)
				{
					if(str[i][j] != 32)
					{
						str[i][j] = table[str[i][j]];
					}
				}
			}
			for(i=0; i<n; i++)
			{
				puts(str[i]);
			}
		}
		else
		{
			puts("No solution.");
		}
		if(count) puts("");
	}
	return 0;
}
