#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	scanf("%1d%1d%1d%1d", &a, &b, &c, &d);
	bool ans = (a == b || b == c || c == d);
	puts(ans ? "Bad" : "Good");
	return 0;
}
