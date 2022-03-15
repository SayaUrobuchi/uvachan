#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		if (c*d <= b)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n", (a-1)/((long long)c*d-b)+1);
		}
	}
	return 0;
}
