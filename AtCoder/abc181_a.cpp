#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	puts((n & 1) ? "Black" : "White");
	return 0;
}
