#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	puts(b >= a-3 && b <= a+2 ? "Yes" : "No");
	return 0;
}
