#include <stdio.h>
#include <math.h>

int x, y;
int r[40000], l[40000], u[40000], d[40000];
int wayx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int wayy[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

void getcoor(int n)
{
	int temp, num;
	if(n == 1)
	{
		x = 0;
		y = 0;
		return;
	}
	temp = sqrt(n-1) + 0.0000001;
	num = temp * temp;
	temp += 1 - (temp*temp == n);
	if(n <= num + temp)
	{
		if(temp % 2)
		{
			x = -(temp/2);
			y = n - num - temp/2 - temp%2;
		}
		else
		{
			x = temp/2;
			y = num + temp/2 - n;
		}
	}
	else
	{
		num += temp;
		if(temp % 2)
		{
			x = n - num - temp/2;
			y = temp/2;
		}
		else
		{
			x = num + temp/2 - n;
			y = -(temp/2);
		}
	}
}

void travel(int x, int y)
{
	if(ab(x) > ab(y))
	{
		if(x > 0)
		{
			printf("%d;", r[x] - y + 1);
		}
		else
		{
			printf("%d;", l[-x] + y + 1);
		}
	}
	else
	{
		if(y > 0)
		{
			printf("%d;", u[y] + x + 1);
		}
		else
		{
			printf("%d;", d[-y] - x + 1);
		}
	}
}

int main()
{
	int n, i, j;
	l[0] = r[0] = u[0] = d[0];
	for(i=1, j=1; i<40000; i++, j+=8)
	{
		r[i] = r[i-1] + j;
	}
	for(i=1, j=5; i<40000; i++, j+=8)
	{
		l[i] = l[i-1] + j;
	}
	for(i=1, j=7; i<40000; i++, j+=8)
	{
		u[i] = u[i-1] + j;
	}
	for(i=1, j=3; i<40000; i++, j+=8)
	{
		d[i] = d[i-1] + j;
	}
	while(scanf("%d", &n) == 1)
	{
		getcoor(n);
		for(i=0; i<9; i++)
		{
			travel(x+wayx[i], y+wayy[i]);
			if(i % 3 == 2)
			{
				printf("\n");
			}
		}
	}
	return 0;
}
