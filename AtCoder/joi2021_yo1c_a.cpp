#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int sum = a + b;
	int dif = a - b;
	printf("%d\n%d\n", max(sum, dif), min(sum, dif));
	return 0;
}
