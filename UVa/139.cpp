#include <stdio.h>
#include <string.h>

int n, l;
int len[2000];
int price[2000];
int idd[2000];
char phone[2000][20];
char area[2000][30];
char str[100];
char buf[100];

int search()
{
	int i, cmp, length;
	for(i=0; i<n; i++)
	{
		cmp = strncmp(str, phone[i], len[i]);
		if(!cmp)
		{
			length = l - len[i];
			if((idd[i] && length > 3 && length < 11) || (!idd[i] && length > 3 && length < 8))
			{
				strcpy(buf, str+len[i]);
				return i;
			}
		}
	}
	return -1;
}

int main()
{
	int i, minute;
	while(scanf("%s%c", phone[n], &str[0]) == 2)
	{
		if(!strcmp(phone[n], "000000"))
		{
			break;
		}
		len[n] = strlen(phone[n]);
		if(phone[n][0] == phone[n][1] && phone[n][0] == '0')
		{
			idd[n] = 1;
		}
		gets(str);
		strcpy(area[n], strtok(str, "$"));
		sscanf(strtok(NULL, "$"), "%d", &price[n]);
		n++;
	}
	while(scanf("%s", str) == 1)
	{
		if(!strcmp(str, "#"))
		{
			break;
		}
		scanf("%d", &minute);
		if(str[0] == '0')
		{
			l = strlen(str);
			i = search();
			if(i == -1)
			{
				printf("%-16s%-35s%7d%13.2lf\n", str, "Unknown", minute, -1.0);
			}
			else
			{
				printf("%-16s%-25s%10s%7d%6.2lf%7.2lf\n", str, area[i], buf, minute, price[i]/100.0, minute*price[i]/100.0);
			}
		}
		else
		{
			printf("%-16s%-25s%10s%7d%6.2lf%7.2lf\n", str, "Local", str, minute, 0.0, 0.0);
		}
	}
	return 0;
}
