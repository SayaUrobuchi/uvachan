#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		printf("%d\n", 21-a-b-c);
	}
	return 0;
}

