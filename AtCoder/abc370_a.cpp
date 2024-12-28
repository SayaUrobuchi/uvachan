#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if (a == b)
	{
		puts("Invalid");
	}
	else
	{
		puts(a ? "Yes" : "No");
	}
	return 0;
}
