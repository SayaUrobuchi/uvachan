#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (c % __gcd(a, b) == 0)
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}
