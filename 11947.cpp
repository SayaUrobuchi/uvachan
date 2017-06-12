#include <stdio.h>

const char *s[12] = {"aquarius", "pisces", "aries", "taurus", "gemini", "cancer", "leo",
	"virgo", "libra", "scorpio", "sagittarius", "capricorn"};

int calc(int m, int y)
{
	if(m == 2)
	{
		return 28+(!(y&3) && (y%100||y%400==0));
	}
	if(m < 8)
	{
		return 30+(m&1);
	}
	return 31-(m&1);
}

const char *get_str(int m, int d)
{
	int t;
	t = m*100+d;
	if(t < 121)
	{
		return s[11];
	}
	else if(t < 220)
	{
		return s[0];
	}
	else if(t < 321)
	{
		return s[1];
	}
	else if(t < 421)
	{
		return s[2];
	}
	else if(t < 522)
	{
		return s[3];
	}
	else if(t < 622)
	{
		return s[4];
	}
	else if(t < 723)
	{
		return s[5];
	}
	else if(t < 822)
	{
		return s[6];
	}
	else if(t < 924)
	{
		return s[7];
	}
	else if(t < 1024)
	{
		return s[8];
	}
	else if(t < 1123)
	{
		return s[9];
	}
	else if(t < 1223)
	{
		return s[10];
	}
	return s[11];
}

int main()
{
	int cas, count, mon, day, year, i;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%2d%2d%4d", &mon, &day, &year);
		for(i=0; i<280; i++)
		{
			day++;
			if(day > calc(mon, year))
			{
				day = 1;
				mon++;
				if(mon > 12)
				{
					year++;
					mon = 1;
				}
			}
		}
		printf("%d %02d/%02d/%04d %s\n", ++cas, mon, day, year, get_str(mon, day));
	}
	return 0;
}
