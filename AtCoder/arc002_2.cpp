#include <iostream>
using namespace std;

int tbl[] = {0, 31, 28, 31, 30, 31, 30, 
				31, 31, 30, 31, 30, 31
};

bool is_leap(int y)
{
	return y % 400 == 0 || (y % 4 == 0 && y % 100);
}

int md(int m, int y)
{
	int leap = 0;
	if (m == 2 && is_leap(y))
	{
		leap = 1;
	}
	return tbl[m] + leap;
}

int main()
{
	int y, m, d;
	scanf("%d/%d/%d", &y, &m, &d);
	while (y % m || y / m % d)
	{
		++d;
		if (d > md(m, y))
		{
			d = 1;
			++m;
			if (m > 12)
			{
				m = 1;
				++y;
			}
		}
	}
	printf("%d/%02d/%02d\n", y, m, d);
	return 0;
}
