#include <iostream>
#include <cstring>
using namespace std;

const char *MONTH[] = {
	"", "JAN", "FEB", "MAR", "APR", 
		"MAY", "JUN", "JUL", "AUG", 
		"SEP", "OCT", "NOV", "DEC"
};
const char *WEEKDAY[] = {
	"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" 
};
const int MD[] = {
	0, 31, 28, 31, 30, 31, 30, 
	   31, 31, 30, 31, 30, 31
};

int find_ary(const char *s, const char *ary[])
{
	int i;
	for (i=0; strcmp(s, ary[i]); i++);
	return i;
}

int find_month(const char *s)
{
	return find_ary(s, MONTH);
}

int find_wd(const char *s)
{
	return find_ary(s, WEEKDAY);
}

int calc(int tm, int td, int w, bool leap)
{
	int d;
	td += tm * 100;
	for (d=102; d<=td; d++)
	{
		w = (w+1) % 7;
		if (d % 100 > MD[d/100] + (d/100 == 2 && leap))
		{
			d += 100 - d%100 + 1;
		}
	}
	return w;
}

int main()
{
	int d;
	char buf[16];
	scanf("%d%s", &d, buf);
	int m = find_month(buf);
	scanf("%s", buf);
	int w = find_wd(buf);
	int t = calc(m, d, w, false);
	int t2 = calc(m, d, w, true);
	if (t == 5 && t2 == 5)
	{
		puts("TGIF");
	}
	else if (t == 5 || t2 == 5)
	{
		puts("not sure");
	}
	else
	{
		puts(":(");
	}
	return 0;
}
