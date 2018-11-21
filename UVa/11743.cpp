#include <stdio.h>

int res;

void calc(int n)
{
	int m;
	while(n)
	{
		res += n%10;
		n /= 10;
		m = n%10;
		m += m;
		res += m/10+m%10;
		n /= 10;
	}
}

int main()
{
	int count, a, b, c, d;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		res = 0;
		calc(a);
		calc(b);
		calc(c);
		calc(d);
		printf(res%10?"Invalid\n":"Valid\n");
	}
	return 0;
}
