#include <iostream>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (n < 40)
		{
			printf("%d\n", 40-n);
		}
		else if (n < 70)
		{
			printf("%d\n", 70-n);
		}
		else if (n < 90)
		{
			printf("%d\n", 90-n);
		}
		else
		{
			puts("expert");
		}
	}
	return 0;
}

