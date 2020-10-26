#include <iostream>

int main()
{
	int n, t;
	while (scanf("%d", &n) == 1)
	{
		t = (n-2018)*12 + 23;
		if (t % 26 + 11 >= 26)
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}
	return 0;
}
