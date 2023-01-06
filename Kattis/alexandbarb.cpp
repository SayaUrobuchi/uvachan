#include <iostream>
using namespace std;

int main()
{
	int n, k, a, b;
	scanf("%d%d%d", &n, &a, &b);
	k = n % (a+b);
	if (k < a)
	{
		puts("Barb");
	}
	else
	{
		puts("Alex");
	}
	return 0;
}