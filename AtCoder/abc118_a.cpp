#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", b%a?b-a:b+a);
	return 0;
}
