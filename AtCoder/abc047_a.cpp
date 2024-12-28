#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	bool ans = (a + b + c == max(a, max(b, c)) * 2);
	puts(ans ? "Yes" : "No");
	return 0;
}
