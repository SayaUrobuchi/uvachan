#include <stdio.h>
#include <string.h>

int tbl[105];
char buf[1000005], s[105];

void low(char *s)
{
	while(*s)
	{
		*s++ |= 32;
	}
}

int main()
{
	int count, m, i, j;
	scanf("%d", &count);
	gets(buf);
	while(count--)
	{
		gets(buf);
		low(buf);
		scanf("%d", &m);
		gets(s);
		tbl[0] = -1;
		while(m--)
		{
			gets(s);
			low(s);
			for(i=1, j=0; s[i]; i++)
			{
				tbl[i] = j;
				while(j >= 0 && s[i] != s[j])
				{
					j = tbl[j];
				}
				j++;
			}
			for(i=0, j=0; buf[i]; i++)
			{
				while(j >= 0 && buf[i] != s[j])
				{
					j = tbl[j];
				}
				j++;
				if(!s[j])
				{
					break;
				}
			}
			printf(buf[i]?"y\n":"n\n");
		}
	}
	return 0;
}
