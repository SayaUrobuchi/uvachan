#include <iostream>
using namespace std;

int calc(int n)
{
	int a, b;
	scanf("%d%d", &a, &b);
	return a * n + (n-1) * n / 2 * b;
}

int main()
{
	int n;
	scanf("%d", &n);
	int a = calc(n);
	int b = calc(n);
	if (a < b)
	{
		puts("Alice");
	}
	else if (a == b)
	{
		puts("=");
	}
	else
	{
		puts("Bob");
	}
	return 0;
}
