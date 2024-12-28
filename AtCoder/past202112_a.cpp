#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	puts(c >= a && d <= b ? "Yes" : "No");
	return 0;
}
