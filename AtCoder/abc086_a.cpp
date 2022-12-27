#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d", &a, &b);
	c = a * b;
	if (c & 1)
	{
		puts("Odd");
	}
	else
	{
		puts("Even");
	}
	return 0;
}