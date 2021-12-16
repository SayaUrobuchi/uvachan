#include <iostream>
using namespace std;

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		printf("%.10lf\n", b+(a-b)/3.0);
	}
	return 0;
}
