#include <iostream>

int calc(int a, int b)
{
	if (a < b)
	{
		std::swap(a, b);
	}
	if (a == 2 && b == 1)
	{
		return 1048576;
	}
	if (a == b)
	{
		return a * 1000;
	}
	return a*10 + b;
}

int main()
{
	int a, b, c, d, p, q;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		if (a == 0 && b == 0 && c == 0 && d == 0)
		{
			break;
		}
		p = calc(a, b);
		q = calc(c, d);
		if (p == q)
		{
			puts("Tie.");
		}
		else
		{
			printf("Player %d wins.\n", p>q?1:2);
		}
	}
	return 0;
}
