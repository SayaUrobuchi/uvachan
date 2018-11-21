#include <stdio.h>
#include <string.h>

int tbl[10];
char str[18][101];

int main()
{
	int i, j;
	char *s, *buf;
	while(gets(str[0]))
	{
		if(!strcmp(str[0], "-1"))
		{
			break;
		}
		for(i=1; i<16; i++)
		{
			memset(tbl, 0, sizeof(tbl));
			for(j=0, s=str[i-1]; s[j]; j++)
			{
				tbl[s[j]-'0']++;
			}
			for(j=0, buf=str[i]; j<10; j++)
			{
				if(tbl[j])
				{
					sprintf(buf, "%d%d\0", tbl[j], j);
					buf += strlen(buf);
				}
			}
			for(j=0, buf=str[i]; j<i; j++)
			{
				if(!strcmp(str[j], buf))
				{
					break;
				}
			}
			if(j < i)
			{
				if(i == 1)
				{
					printf("%s is self-inventorying\n", str[0]);
				}
				else if(j + 1 == i)
				{
					printf("%s is self-inventorying after %d steps\n", str[0], j);
				}
				else
				{
					printf("%s enters an inventory loop of length %d\n", str[0], i-j);
				}
				break;
			}
		}
		if(i == 16)
		{
			printf("%s can not be classified after 15 iterations\n", str[0]);
		}
	}
	return 0;
}
