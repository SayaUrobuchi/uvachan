#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	bool ans = false;
	if (a == b && a == c)
	{
		ans = true;
	}
	else if (a + b + c == max(a, max(b, c)) * 2)
	{
		ans = true;
	}
	puts(ans ? "Yes" : "No");
	return 0;
}
