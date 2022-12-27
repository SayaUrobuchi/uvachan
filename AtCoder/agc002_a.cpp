#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (a <= 0 && b >= 0)
	{
		puts("Zero");
	}
	else if ((min(b, 0)-a+1) & 1)
	{
		puts("Negative");
	}
	else
	{
		puts("Positive");
	}
	return 0;
}