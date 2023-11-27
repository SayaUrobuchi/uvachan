#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a <= b && a <= c)
	{
		puts("Monnei");
	}
	else if (b <= a && b <= c)
	{
		puts("Fjee");
	}
	else
	{
		puts("Dolladollabilljoll");
	}
	return 0;
}
