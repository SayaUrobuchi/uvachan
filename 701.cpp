#include <stdio.h>
#include <math.h>

double ab(double now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int cmp(double p, double q)
{
	if(ab(p - q) < 0.0000001)
	{
		return 1;
	}
	return 0;
}

int main()
{
	unsigned int n, temp;
	double p, q, left, right, i, len;
	const double l = log2(10.0);
	while(scanf("%u", &n) == 1)
	{
		p = log2(n);
		q = log2(n+1);
		temp = n;
		for(len=0; temp; len++, temp/=10);
		for(i=len+1; ; i++)
		{
			left = i * l;
			right = q + left;
			left += p;
			temp = (int)right;
			if((temp > (int)left || cmp(temp, left)) && temp < right)
			{
				printf("%d\n", temp);
				break;
			}
		}
	}
	return 0;
}
