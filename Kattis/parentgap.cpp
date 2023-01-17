#include <iostream>
using namespace std;

bool getleap(int i)
{
	return (i % 400 == 0) || (i % 4 == 0 && i % 100);
}

int main()
{
	int yy, i, week, mdd;
	bool leap;
	scanf("%d", &yy);
	for (i=2000, week=6; i<yy; i++)
	{
		leap = getleap(i);
		week = (week + 365 + leap) % 7;
	}
	leap = getleap(yy);
	week = (week + 31 + 28 + 31 + 30 + leap) % 7;
	mdd = 1;
	if (week)
	{
		mdd += 7 - week;
	}
	mdd += 7;
	if (mdd + 21 <= 31)
	{
		puts("6 weeks");
	}
	else
	{
		puts("5 weeks");
	}
	return 0;
}
