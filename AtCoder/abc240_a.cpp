#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int diff = abs(a - b);
	puts(diff == 9 || diff == 1 ? "Yes" : "No");
	return 0;
}
