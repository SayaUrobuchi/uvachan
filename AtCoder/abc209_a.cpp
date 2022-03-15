#include <iostream>
using namespace std;

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		printf("%d\n", max(0, b-a+1));
	}
	return 0;
}
