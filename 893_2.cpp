#include <stdio.h>

int leap(int y)
{
	return y % 400 == 0 || (y % 100 && y % 4 == 0);
}

int day(int m, int y)
{
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		return 31;
	}
	else if(m == 2)
	{
		return 28 + leap(y);
	}
	return 30;
}

int main()
{
	int n, d, m, y;
	while(scanf("%d%d%d%d", &n, &d, &m, &y) == 4)
	{
		if(n == 0 && d == 0 && m == 0 && y == 0)
		{
			break;
		}
		for(; n; n--)
		{
			if(d == 1 && m == 1)
			{
				break;
			}
			d++;
			if(d > day(m, y))
			{
				d = 1;
				m++;
				if(m > 12)
				{
					m = 1;
					y++;
				}
			}
		}
		y += ((n / ((365 << 2) + 1)) << 2);
		n %= (365 << 2) + 1;
		for(; n>=365+leap(y); n-=365+leap(y), y++);
		if(leap(y) == 0 && d == 29 && m == 2)
		{
			d = 1;
			m = 3;
		}
		for(; n; n--)
		{
			d++;
			if(d > day(m, y))
			{
				d = 1;
				m++;
				if(m > 12)
				{
					m = 1;
					y++;
				}
			}
		}
		printf("%d %d %d\n", d, m, y);
	}
	return 0;
}
