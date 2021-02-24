#include <iostream>

int tbl[] = {120, 219, 320, 420, 520, 621, 722, 822, 921, 1022, 1122, 1221, 9999};
const char *nam[] = {"Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", 
					 "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"};
const char *key[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
char buf[1024];
int mon[128<<14];

int dec(const char *s)
{
	return (s[0]<<14)+(s[1]<<7)+(s[2]);
}

int trans(const char *s)
{
	return mon[dec(s)];
}

int main()
{
	int count, d, m, t, i;
	for (i=0; i<12; i++)
	{
		mon[dec(key[i])] = i+1;
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%s", &d, buf);
		m = trans(buf);
		t = m*100 + d;
		for (i=0; i<13; i++)
		{
			if (t <= tbl[i])
			{
				break;
			}
		}
		printf("%s\n", nam[i]);
	}
	return 0;
}
