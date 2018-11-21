#include <stdio.h>

int main()
{
	int a, b, c, d, res;
	while(scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		if(a == 0 && b == 0 && c == 0 && d == 0)
		{
			break;
		}
		res = c*60+d-(a*60+b);
		if(res < 0)
		{
			res += 24*60;
		}
		printf("%d\n", res);
	}
	return 0;
}
