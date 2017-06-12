#include <stdio.h>

int trans[1000];
int map[1000][1000];
char name[1000][100];
char buf[10000];

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

char* deal(int now)
{
	if(now < 0)
	{
		buf[0] = '-';
	}
	else
	{
		buf[0] = ' ';
	}
	sprintf(buf+1, "%d", ab(now)/100);
	return buf;
}

int main()
{
	int i, j, temp, record, money;
	while(scanf("%d", &temp) == 1)
	{
		gets(name[temp]);
		if(!temp)
		{
			break;
		}
	}
	while(scanf("%d%d", &record, &money) == 2)
	{
		if(!record)
		{
			break;
		}
		map[record/1000][record%1000] += money;
		trans[record/1000] += money;
	}
	for(i=0; i<1000; i++)
	{
		if(trans[i])
		{
			printf("*** Transaction %3d is out of balance ***\n", i);
			for(j=0, temp=0; j<1000; j++)
			{
				if(map[i][j])
				{
					printf("%3d %-31s%7s.%02d\n", j, name[j], deal(map[i][j]), ab(map[i][j])%100);
					temp += map[i][j];
				}
			}
			printf("999 %-31s%7s.%02d\n\n", "Out of Balance", deal(-temp), ab(temp)%100);
		}
	}
	scanf(" ");
	return 0;
}
