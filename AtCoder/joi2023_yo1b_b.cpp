#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int res = 0;
	if (a < b)
	{
		res = -1;
	}
	else if (a > b)
	{
		res = 1;
	}
	printf("%d\n", res);
	return 0;
}
