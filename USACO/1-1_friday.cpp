/*
ID: sa072682
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, week[7], day;
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	scanf("%d", &n);
	memset(week, 0, sizeof(week));
	day = 4;
	n += 1900;
	for(i=1900; i<n; i++)
	{
		day += 31;
		day %= 7;
		week[day]++;
		day += 31;
		day %= 7;
		week[day]++;
		day += 28;
		if((!(i % 4) && i % 100) || !(i % 400))
		{
			day++;
		}
		day %= 7;
		week[day]++;
		day += 31;
		day %= 7;
		week[day]++;
		day += 30;
		day %= 7;
		week[day]++;
		day += 31;
		day %= 7;
		week[day]++;
		day += 30;
		day %= 7;
		week[day]++;
		day += 31;
		day %= 7;
		week[day]++;
		day += 31;
		day %= 7;
		week[day]++;
		day += 30;
		day %= 7;
		week[day]++;
		day += 31;
		day %= 7;
		week[day]++;
		day += 30;
		day %= 7;
		week[day]++;
	}
	printf("%d %d %d %d %d %d %d\n", week[0], week[1], week[2], week[3], week[4], week[5], week[6]);
	return 0;
}
