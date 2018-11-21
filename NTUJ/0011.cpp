#include <stdio.h>

int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap(int y)
{
	return y%4 == 0 && (y%100 || y%400 == 0);
}

int mday(int m, int y)
{
	return md[m] + (m==2&&leap(y));
}

int main()
{
	int cas, count, i, m, d, y, om, od, oy, tm, td;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d/%d/%d%d/%d", &om, &od, &oy, &tm, &td);
		for(i=-1, m=om, d=od-1, y=oy; i>=-7; i--, d--)
		{
			if(d < 1)
			{
				m--;
				if(m < 1)
				{
					y--;
					m += 12;
				}
				d += mday(m, y);
			}
			if(d == td && m == tm)
			{
				if(i < -1)
				{
					printf("%d %d/%d/%d IS %d DAYS PRIOR\n", ++cas, m, d, y, -i);
				}
				else
				{
					printf("%d %d/%d/%d IS %d DAY PRIOR\n", ++cas, m, d, y, -i);
				}
				break;
			}
		}
		if(i >= -7)
		{
			continue;
		}
		for(i=0, m=om, d=od, y=oy; i<=7; i++, d++)
		{
			if(d > mday(m, y))
			{
				d -= mday(m, y);
				m++;
				if(m > 12)
				{
					m -= 12;
					y++;
				}
			}
			if(d == td && m == tm)
			{
				if(i)
				{
					if(i == 1)
					{
						printf("%d %d/%d/%d IS %d DAY AFTER\n", ++cas, m, d, y, i);
					}
					else
					{
						printf("%d %d/%d/%d IS %d DAYS AFTER\n", ++cas, m, d, y, i);
					}
				}
				else
				{
					printf("%d SAME DAY\n", ++cas);
				}
				break;
			}
		}
		if(i <= 7)
		{
			continue;
		}
		printf("%d OUT OF RANGE\n", ++cas);
	}
	return 0;
}
