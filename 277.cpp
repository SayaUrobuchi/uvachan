#include <stdio.h>
#include <string.h>

char buf[2008];
char s[10][100];
char stemp[2008];
char record[2008];

int main()
{
	int count, n, i, j, temp;
	char *ptr;
	scanf("%d", &count);
	gets(buf);
	gets(buf);
	while(count--)
	{
		printf("Item Id,Item Desc,Item Price\n");
		n = -1;
		while(gets(buf))
		{
			if(!buf[0])
			{
				break;
			}
			s[0][0] = s[1][0] = s[2][0] = s[3][0] = s[4][0] = 0;
			for(i=0, j=0, ptr=buf; buf[i]; i++)
			{
				if(buf[i] == ',')
				{
					buf[i] = 0;
					strcpy(s[j++], ptr);
					ptr = buf + i + 1;
				}
			}
			strcpy(s[j++], ptr);
			ptr = buf + i + 1;
			sscanf(s[0], "%d", &temp);
			if(temp != n)
			{
				strcpy(stemp, s[1]);
				n = temp;
			}
			ptr = record;
			sprintf(ptr, "%03d%s,\0", temp, s[2]);
			if(strlen(ptr) > 14)
			{
				continue;
			}
			ptr += strlen(ptr);
			if(s[1][0])
			{
				sprintf(buf, "%s\0", s[1]);
			}
			else
			{
				if(stemp[0])
				{
					sprintf(buf, "%s\0", stemp);
				}
				else
				{
					continue;
				}
			}
			if(s[3][0])
			{
				sprintf(buf+strlen(buf), "-%s\0", s[3]);
			}
			sprintf(ptr, "%.30s,\0", buf);
			ptr += strlen(ptr);
			if(sscanf(s[4], "%d", &temp) == 1)
			{
				sprintf(ptr, "%d.%02d\0", temp/100, temp%100);
			}
			else
			{
				sprintf(ptr, "0.00\0");
			}
			puts(record);
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
