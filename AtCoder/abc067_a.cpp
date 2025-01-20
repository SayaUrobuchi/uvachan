#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	bool possible = (a%3 == 0 || b%3 == 0 || (a+b)%3 == 0);
	puts(possible ? "Possible" : "Impossible");
	return 0;
}
