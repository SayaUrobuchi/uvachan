#include <iostream>

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		puts((n&1)?"Bob":"Alice\n1");
	}
	return 0;
}
