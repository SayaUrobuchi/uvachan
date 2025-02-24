#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &c, &a, &b);
	puts(abs(a-b) > c-a-b ? "Yes" : "No");
	return 0;
}
