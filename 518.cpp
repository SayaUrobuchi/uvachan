#include <stdio.h>
#include <string.h>

int mday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int lmday[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char buf[1001];

int leap(int now)
{
	return !(now%4) && (now%100||!(now%400));
}

int getday(int y, int m, int d)
{
	if(leap(y))
	{
		return (y-1)*365+(y-1)/4-(y-1)/100+(y-1)/400+lmday[m-1]+d;
	}
	return (y-1)*365+(y-1)/4-(y-1)/100+(y-1)/400+mday[m-1]+d;
}

int main()
{
	int i, y1, m1, d1, h1, min1, s1, y2, m2, d2, h2, min2, s2, num;
	long long total1, total2, unit;
	for(i=1; i<=12; i++)
	{
		mday[i] += mday[i-1];
		lmday[i] += lmday[i-1];
	}
	while(scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%s", &y1, &m1, &d1, &h1, &min1, &s1, &y2, &m2, &d2, &h2, &min2, &s2, &num, buf) == 14)
	{
		if(!strcmp(buf, "year"))
		{
			printf("%d\n", (y2-y1-!(m1==1&&d1==1))/num);
		}
		else if(!strcmp(buf, "month"))
		{
			m1 += y1 * 12;
			m2 += y2 * 12;
			printf("%d\n", (m2-m1-!(d1==1))/num);
		}
		else if(!strcmp(buf, "day"))
		{
			d1 = getday(y1, m1, d1);
			d2 = getday(y2, m2, d2);
			printf("%d\n", (d2-d1-!(!h1&&!min1&&!s1))/num);
		}
		else if(!strcmp(buf, "hour"))
		{
			total1 = getday(y1, m1, d1);
			total2 = getday(y2, m2, d2);
			total1 *= 24;
			total2 *= 24;
			total1 += h1;
			total2 += h2;
			printf("%lld\n", (total2-total1-!(!min1&&!s1))/num);
		}
		else if(!strcmp(buf, "minute"))
		{
			total1 = getday(y1, m1, d1);
			total2 = getday(y2, m2, d2);
			total1 *= 24*60;
			total2 *= 24*60;
			total1 += h1*60+min1;
			total2 += h2*60+min2;
			printf("%lld\n", (total2-total1-!(!s1))/num);
		}
		else
		{
			total1 = getday(y1, m1, d1);
			total2 = getday(y2, m2, d2);
			total1 *= 86400;
			total2 *= 86400;
			total1 += h1*3600+min1*60+s1;
			total2 += h2*3600+min2*60+s2;
			printf("%lld\n", (total2-total1)/num);
		}
	}
	return 0;
}
