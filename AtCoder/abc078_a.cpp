#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%x%x", &a, &b);
	if (a < b)
	{
		puts("<");
	}
	else if (a == b)
	{
		puts("=");
	}
	else
	{
		puts(">");
	}
	return 0;
}
