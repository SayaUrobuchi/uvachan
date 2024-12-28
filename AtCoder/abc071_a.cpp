#include <iostream>
using namespace std;

int main()
{
	int c, a, b;
	scanf("%d%d%d", &c, &a, &b);
	if (abs(c-a) < abs(c-b))
	{
		puts("A");
	}
	else
	{
		puts("B");
	}
	return 0;
}
