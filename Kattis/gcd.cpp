#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	while ((a%=b) && (b%=a));
	return a+b;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", gcd(a, b));
	return 0;
}
