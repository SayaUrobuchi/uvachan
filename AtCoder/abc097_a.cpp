#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (abs(a-c) <= d || (abs(a-b) <= d && abs(b-c) <= d))
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
