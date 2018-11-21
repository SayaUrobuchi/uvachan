#include <stdio.h>

int calc(int a, int i)
{
	int j, k, res;
	if(a == 0)
	{
		return 0;
	}
	if(i == 0)
	{
		return 1;
	}
	i %= 4;
	if(!i)
	{
		i = 4;
	}
	for(j=0, k=1, res=0; j<i; j++)
	{
		k*=a;
	}
	return k%10;
}

int main()
{
	int count, a, b, c, d, e, res, t;
	int i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &a, &b, &c);
		a %= 10;
		res = 0;
		if(b == 0)
		{
			res = 1;
			b++;
		}
		e = d = c-b+1;
		d %= 4;
		e /= 4;
		for(i=b; i<b+d; i++)
		{
			res += calc(a, i);
		}
		for(b=i, d=0; i<b+4; i++)
		{
			d += calc(a, i);
		}
		res += (long long)d*e%10;
		printf("%d\n", res%10);
	}
	return 0;
}
