#include <iostream>
using namespace std;

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		if (a > 0 && b > 0)
		{
			puts("Alloy");
		}
		else if (a > 0)
		{
			puts("Gold");
		}
		else
		{
			puts("Silver");
		}
	}
	return 0;
}

