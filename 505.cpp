#include <stdio.h>
#include <string.h>

int monthday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int lmonthday[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char weekname[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
char monthname[12][4] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
char buf[1001];
char weekstr[1001], monthstr[1001], yearstr[1001], timestr[1001], tzonestr[1001];

int getweek(char *s)
{
	int i;
	s[3] = 0;
	for(i=0; /*i<7*/; i++)
	{
		if(!strcmp(s, weekname[i]))
		{
			return i;
		}
	}
}

int getmonth(char *s)
{
	int i;
	for(i=0; /*i<12*/; i++)
	{
		if(!strcmp(s, monthname[i]))
		{
			return i + 1;
		}
	}
}

int gettzone(char *s)
{
	int hr, min;
	if(!strcmp(s, "UT"))
	{
		return gettzone("-0000");
	}
	if(!strcmp(s, "GMT"))
	{
		return gettzone("-0000");
	}
	if(!strcmp(s, "EDT"))
	{
		return gettzone("-0400");
	}
	if(!strcmp(s, "CDT"))
	{
		return gettzone("-0500");
	}
	if(!strcmp(s, "MDT"))
	{
		return gettzone("-0600");
	}
	if(!strcmp(s, "PDT"))
	{
		return gettzone("-0700");
	}
	hr = (s[1]-48)*10+s[2]-48;
	hr *= 3600;
	min = (s[3]-48)*10+s[4]-48;
	min *= 60;
	if(s[0] == '-')
	{
		return -(hr+min);
	}
	return hr + min;
}

int leap(int now)
{
	return !(now % 4) && (now % 100 || !(now % 400));
}

int mod(int month)
{
	if(month == 0)
	{
		return 12;
	}
	return month;
}

int main()
{
	int stdtime, week, second, minute, hour, day, month, year, time, tzone;
	int *nowmdays;
	stdtime = gettzone("+0300");
	while(gets(buf))
	{
		sscanf(buf, "%s%d%s%s%s%s", weekstr, &day, monthstr, yearstr, timestr, tzonestr);
		week = getweek(weekstr);
		month = getmonth(monthstr);
		sscanf(yearstr, "%d", &year);
		if(!yearstr[2])
		{
			year += 1900;
		}
		sscanf(timestr, "%d:%d:%d", &hour, &minute, &second);
		tzone = gettzone(tzonestr);
		if(leap(year))
		{
			nowmdays = lmonthday;
		}
		else
		{
			nowmdays = monthday;
		}
		second += stdtime - tzone;
		if(stdtime >= tzone)
		{
			if(second >= 60)
			{
				minute += second / 60;
				second %= 60;
				if(minute >= 60)
				{
					hour += minute / 60;
					minute %= 60;
					if(hour >= 24)
					{
						day += hour / 24;
						week += hour / 24;
						week %= 7;
						hour %= 24;
						if(day > nowmdays[month])
						{
							day -= nowmdays[month];
							month++;
							if(month > 12)
							{
								year++;
								month -= 12;
							}
						}
					}
				}
			}
		}
		else
		{
			for(; second<0; second+=60, minute--);
			for(; minute<0; minute+=60, hour--);
			for(; hour<0; hour+=24, day--, week--);
			for(; week<0; week+=7);
			for(; day<1; day+=nowmdays[mod(month-1)], month--);
			for(; month<1; month+=12, year--);
		}
		printf("%s, %02d %s %04d %02d:%02d:%02d +0300\n", weekname[week], day, monthname[month-1], year, hour, minute, second);
	}
	return 0;
}
