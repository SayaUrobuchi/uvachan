#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int sum = a + b + c + d;
	int h = sum / 60;
	int m = sum % 60;
	printf("%d\n%d\n", h, m);
	return 0;
}
