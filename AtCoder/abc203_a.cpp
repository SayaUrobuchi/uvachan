#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		if (a == c)
		{
			printf("%d\n", b);
		}
		else if (a == b)
		{
			printf("%d\n", c);
		}
		else if (b == c)
		{
			printf("%d\n", a);
		}
		else
		{
			puts("0");
		}
	}
	return 0;
}

