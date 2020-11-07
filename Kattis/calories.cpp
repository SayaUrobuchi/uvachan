#include <iostream>
using namespace std;

int rtbl[] = {9, 4, 4, 4, 7};
int ary[8];
char unit[8];
double total, fat;

void calc(string &s)
{
	int i, rat;
	double real;
	sscanf(s.c_str(), "%d%c%d%c%d%c%d%c%d%c", &ary[0], &unit[0], &ary[1], &unit[1], &ary[2], &unit[2], 
											  &ary[3], &unit[3], &ary[4], &unit[4]);
	for (i=0, real=0, rat=100; i<5; i++)
	{
		if (unit[i] == '%')
		{
			rat -= ary[i];
		}
		else if (unit[i] == 'C')
		{
			real += ary[i];
		}
		else
		{
			real += ary[i]*rtbl[i];
		}
	}
	real = real*100.0/rat;
	total += real;
	if (unit[0] == '%')
	{
		fat += real*ary[0]/100;
	}
	else if (unit[0] == 'C')
	{
		fat += ary[0];
	}
	else
	{
		fat += ary[0] * rtbl[0];
	}
}

int main()
{
	string s;
	while (getline(cin, s))
	{
		if (s[0] == '-')
		{
			break;
		}
		fat = 0;
		total = 0;
		calc(s);
		while (getline(cin, s))
		{
			if (s[0] == '-')
			{
				break;
			}
			calc(s);
		}
		printf("%.0lf%%\n", fat*100/total);
	}
	return 0;
}
