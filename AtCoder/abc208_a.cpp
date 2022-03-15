#include <iostream>
using namespace std;

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		puts((b>=a&&b<=a*6)?"Yes":"No");
	}
	return 0;
}
