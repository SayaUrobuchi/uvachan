#include <iostream>

char cmd[1024];

int main()
{
	int n, i;
	long long a, b, last, res;
	while (scanf("%d", &n) == 1)
	{
		for (last=1, i=0; i<n; i++, last=res)
		{
			scanf("%lld%s%lld", &a, cmd, &b);
			if (*cmd == '+')
			{
				res = (a + b) - last;
			}
			else if (*cmd == '-')
			{
				res = (a - b) * last;
			}
			else if (*cmd == '*')
			{
				res = (a*b) * (a*b);
			}
			else
			{
				res = ((a+1) >> 1);
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
