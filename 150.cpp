#include <stdio.h>
#include <string.h>

int monthnum[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int lmonthnum[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char weekname[7][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char monthname[12][20] = {"January", "February", "March", "April", "May", "June", 
						  "July", "August", "September", "October", "November", "December"};
char str[1001];
char buf1[1001], buf2[1001];

int getweekdays(char *s)
{
	int i;
	for(i=0; i<7; i++)
	{
		if(!strcmp(weekname[i], s))
		{
			return i;
		}
	}
	return -1;
}

int getmonths(char *s)
{
	int i;
	for(i=0; i<12; i++)
	{
		if(!strcmp(monthname[i], s))
		{
			return i + 1;
		}
	}
	return 0;
}

int getstandard(int d, int m, int y, int *ptr)
{
	return d + ptr[m-1] + (y - 1) * 365 - 1;
}

int oldleap(int now)
{
	return !(now % 4);
}

int newleap(int now)
{
	return !(now % 4) && (now % 100 || !(now % 400));
}

int getoldstyle(int d, int m, int y)
{
	if(oldleap(y))
	{
		return getstandard(d, m, y, lmonthnum) + (y-1) / 4 - 1;
	}
	else
	{
		return getstandard(d, m, y, monthnum) + (y-1) / 4 - 1;
	}
}

int getnewstyle(int d, int m, int y)
{
	if(newleap(y))
	{
		return getstandard(d, m, y, lmonthnum) + (y-1) / 4 - (y-1) / 100 + (y-1) / 400 + 1;
	}
	else
	{
		return getstandard(d, m, y, monthnum) + (y-1) / 4 - (y-1) / 100 + (y-1) / 400 + 1;
	}
}

void printnewstyle(int days)
{
	int i, d, m, y;
	int *ptr;
	y = (days / (365*303+366*97)) * 400;
	days %= 365*303+366*97;
	y += (days / (365*76+366*24)) * 100;
	days %= 365*76+366*24;
	y += (days / (365*3+366)) << 2;
	days %= 365*3+366;
	y += days / 365;
	days %= 365;
	y++;
	if(newleap(y))
	{
		ptr = lmonthnum;
	}
	else
	{
		ptr = monthnum;
	}
	for(i=1; i<=12; i++)
	{
		if(ptr[i] > days)
		{
			break;
		}
	}
	m = i - 1;
	d = days - ptr[m];
	printf("%s %d %s %d\n", buf1, d+1, monthname[m], y);
}

void printoldstyle(int days)
{
	int i, d, m, y;
	int *ptr;
	y = (days / (365*3+366)) << 2;
	days %= 365*3+366;
	y += days / 365;
	days %= 365;
	y++;
	if(oldleap(y))
	{
		ptr = lmonthnum;
	}
	else
	{
		ptr = monthnum;
	}
	for(i=1; i<=12; i++)
	{
		if(ptr[i] > days)
		{
			break;
		}
	}
	m = i - 1;
	d = days - ptr[m];
	printf("%s %d* %s %d\n", buf1, d+1, monthname[m], y);
}

int main()
{
	int i, weekdays, days, months, years, totaldays;
	for(i=2; i<=12; i++)
	{
		monthnum[i] += monthnum[i-1];
		lmonthnum[i] += lmonthnum[i-1];
	}
	while(gets(str))
	{
		if(!strcmp(str, "#") || str[0] == '#')
		{
			break;
		}
		sscanf(str, "%s%d%s%d", buf1, &days, buf2, &years);
		weekdays = getweekdays(buf1);
		months = getmonths(buf2);
		totaldays = getoldstyle(days, months, years);
		/*printf("%d\n", totaldays);
		printf("%d\n", totaldays % 7);*/
		if(1)
		if(weekdays != totaldays % 7)
		{
			/*printf("TOTAL %d\n", totaldays);*/
			totaldays = getnewstyle(days, months, years);
			/*printf("TOTAL %d\n", totaldays);*/
			printoldstyle(totaldays+1);
		}
		else
		{
			/*printf("TOTAL %d\n", totaldays);
			totaldays = getnewstyle(days, months, years);*/
			/*printf("TOTAL %d\n", totaldays);*/
			printnewstyle(totaldays-1);
		}
		if(0)
		if(weekdays == totaldays % 7)
		{
			/*printf("TOTAL %d\n", totaldays);
			totaldays = getnewstyle(days, months, years);*/
			/*printf("TOTAL %d\n", totaldays);*/
			printnewstyle(totaldays-1);
		}
		else
		{
			/*printf("TOTAL %d\n", totaldays);*/
			totaldays = getnewstyle(days, months, years);
			/*printf("TOTAL %d\n", totaldays);*/
			printoldstyle(totaldays+1);
		}
	}
	return 0;
}
