#include <iostream>

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		c = std::max(0, c-a);
		printf("%d\n", (c-1)/(a-b)+2);
	}
	return 0;
}
