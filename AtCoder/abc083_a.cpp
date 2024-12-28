#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int l = a + b;
	int r = c + d;
	if (l == r)
	{
		puts("Balanced");
	}
	else if (l > r)
	{
		puts("Left");
	}
	else
	{
		puts("Right");
	}
	return 0;
}
