#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%*d%d%d", &a, &b);
	c = a*10 + b;
	if (c % 4 == 0)
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}