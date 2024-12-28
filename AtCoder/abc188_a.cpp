#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (a+3 > b && b+3 > a)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
